#include <stdio.h>
#include <stdlib.h>

struct Database{
 int** addre;
};
struct Connection{
    struct Database *db;
  int *age;
  int year;
};

int fun (int n){

  if (n<=1)
    {
      return 1;
    }
  else {
    /* int *p =(int*)malloc(sizeof(int)); */
    /* free(p); */
    return n + fun(n-1);
  }
}

int func()
{

  int **q;
  int n = 1 + 5;

 struct Connection *conn = malloc(sizeof(struct Connection));

 int *p = (int*)malloc(sizeof(int));

 int m = 1;

 int c ;
 scanf("%d",&c);

 conn->db =malloc(sizeof(struct Database));

  if(conn)
    {
      if(conn->db) free(conn->db);

      m = m+ 2;

      free(conn);

    }

  return 0;


}

int main()
{
  int uio ;
 scanf("%d",&uio);
  int *p = (int*)malloc(sizeof(int));
  switch (uio) {
  case 0: break;
  case 1:  free(p);printf("this is num 1\n"); if(uio) {free(p);} else {return  0; };  break;
  case 2:  free(p);printf("this is num 2\n"); break;
  case 3:  free(p);uio++; int m = 3; m--; break; printf("this is num 3\n"); free(p);break;
  case 4:  printf("this is num 4\n");break;
  case 5: break;
  default:  break;
  }

  return 0;
}
