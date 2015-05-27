/*
 * The MIT License (MIT)
 *
 * Copyright © 2015 Franklin "Snaipe" Mathieu <http://snai.pe/>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <errno.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <string.h>
#include <assert.h>

#include "config.h"
#include "mman.h"
#include "array.h"
#undef smalloc

s_allocator smalloc_allocator = {malloc, free};

__attribute__ ((pure))
void *get_smart_ptr_meta(void *ptr) {
    assert((size_t) ptr == align((size_t) ptr));

    s_meta *meta = get_meta(ptr);
    assert(meta->ptr == ptr);

    size_t head_size = meta->kind & SHARED ? sizeof (s_meta_shared) : sizeof (s_meta);
    size_t *metasize = (size_t *) ptr - 1;
    if (*metasize == head_size)
        return NULL;

    return (char *) meta + head_size;
}

void *sref(void *ptr) {
    s_meta *meta = get_meta(ptr);
    assert(meta->ptr == ptr);
    assert(meta->kind == SHARED);
    ((s_meta_shared *) meta)->ref_count++;
    return ptr;
}

__attribute__ ((malloc))
INLINE static void *alloc_entry(size_t head, size_t size, size_t metasize) {
    const size_t totalsize = head + size + metasize + sizeof (size_t);
#ifdef SMALLOC_FIXED_ALLOCATOR
    return malloc(totalsize);
#else /* !SMALLOC_FIXED_ALLOCATOR */
    return smalloc_allocator.alloc(totalsize);
#endif /* !SMALLOC_FIXED_ALLOCATOR */
}

INLINE static void dealloc_entry(s_meta *meta, void *ptr) {
    if (meta->dtor) {
        void *user_meta = get_smart_ptr_meta(ptr);
        if (meta->kind & ARRAY) {
            s_meta_array *arr_meta = (void *) (meta + 1);
            for (size_t i = 0; i < arr_meta->nmemb; ++i)
                meta->dtor(ptr + arr_meta->size * i, user_meta);
        } else
            meta->dtor(ptr, user_meta);
    }

#ifdef SMALLOC_FIXED_ALLOCATOR
    free(meta);
#else /* !SMALLOC_FIXED_ALLOCATOR */
    smalloc_allocator.dealloc(meta);
#endif /* !SMALLOC_FIXED_ALLOCATOR */
}

__attribute__ ((malloc))
static void *smalloc_impl(s_smalloc_args *args) {
    if (!args->size)
        return NULL;

    // align the sizes to the size of a word
    size_t aligned_metasize = align(args->meta.size);
    size_t size = align(args->size);

    size_t head_size = args->kind & SHARED ? sizeof (s_meta_shared) : sizeof (s_meta);
    s_meta_shared *ptr = alloc_entry(head_size, size, aligned_metasize);
    if (ptr == NULL)
        return NULL;

    char *shifted = (char *) ptr + head_size;
    if (args->meta.size && args->meta.data)
        memcpy(shifted, args->meta.data, args->meta.size);

    size_t *sz = (size_t *) (shifted + aligned_metasize);
    *sz = head_size + aligned_metasize;

    *(s_meta*) ptr = (s_meta) {
        .kind = args->kind,
        .dtor = args->dtor,
#ifndef NDEBUG
        .ptr = sz + 1
#endif
    };

    if (args->kind & SHARED)
        ptr->ref_count = ATOMIC_VAR_INIT(1);

    return sz + 1;
}

__attribute__ ((malloc))
INLINE static void *smalloc_array(s_smalloc_args *args) {
    char new_meta[align(args->meta.size + sizeof(s_meta_array))];
    s_meta_array *arr_meta = (void *) new_meta;
    *arr_meta = (s_meta_array) {
        .size = args->size,
        .nmemb = args->nmemb,
    };
    memcpy(arr_meta + 1, args->meta.data, args->meta.size);
    return smalloc_impl(&(s_smalloc_args) {
            .size = args->nmemb * args->size,
            .kind = args->kind | ARRAY,
            .dtor = args->dtor,
            .meta = { &new_meta, sizeof (new_meta) },
        });
}

__attribute__ ((malloc))
void *smalloc(s_smalloc_args *args) {
    return (args->nmemb == 0 ? smalloc_impl : smalloc_array)(args);
}

void sfree(void *ptr) {
    if (!ptr) return;

    assert((size_t) ptr == align((size_t) ptr));
    s_meta *meta = get_meta(ptr);
    assert(meta->ptr == ptr);

    if (meta->kind == SHARED && --((s_meta_shared *) meta)->ref_count)
        return;

    dealloc_entry(meta, ptr);
}
