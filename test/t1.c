#include <stdio.h>
#include <stdlib.h>

/* #define ROWS 30 */

/* typedef struct Address { */
/*     int id; */
/*     int set; */
/* } Address; */

/* typedef struct Database { */
/*     struct Address rows[ROWS]; */
/* } Database; */

/* typedef struct Connection { */
/*     /\* FILE  *file; *\/ */
/*   int num; */
/*     struct Database *db; */
/* }Connection; */

/* void f(void (*)(unsigned int)); */
int func(int);


int main()
{
    /* struct Connection *conn = malloc(sizeof(struct Connection)); */
    /* conn->db = malloc(sizeof(struct Database)); */

  int *q = (int*)malloc(sizeof(int));
  int *r = (int*)malloc(sizeof(int));
  int c =0;
  scanf("%d",&c);

  if(q)
    {
      int m = 1;

      if(c>1) // raiseNullExExpr (BinOp(..)) (...)
        {

          /* printf("%d\n", conn->num); */
          /* f(free); */
          /* printf("%d\n",*q + 1); */
          /* q =(int *)malloc(sizeof(int)); */
          /* q = func(*q); */
          /* int m = *q; */
          /* printf("%x\n",*q); */
          int m = *q;
        }

      free(q);

    }

  /*
    int m = 1;
    if (c > 1) {
      q = r;
      int m = *q;
     }
     free(q)
   */

  return 0;
}
