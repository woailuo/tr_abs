#include <stdio.h>
#include <stdlib.h>


void f(void (*)(unsigned int));
int func(int);


int main()
{
  int *q = (int*)malloc(sizeof(int));
  int *r = (int*)malloc(sizeof(int));
  int c =0;
  scanf("%d",&c);

  if(q)
    {

      /* if(c>1) // raiseNullExExpr (BinOp(..)) (...) */
      /*   { */
      /*     /\* q = r; *\/ */
      /*     /\* printf("%d\n", conn->num); *\/ */
      /*     /\* f(free); *\/ */
      /*     printf("%x\n",q->f); */
      /*     /\* q =(int *)malloc(sizeof(int)); *\/ */
      /*     /\* q = func(*q); *\/ */
      /*     /\* int m = *q; *\/ */
      /*     /\* printf("%x\n",*q); *\/ */
      /*     int m = *q; */
      /*   } */
      int *m = q;
      free(m);
      /* free(q); */
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
