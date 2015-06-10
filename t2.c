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



int main()
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

      free(conn->db->addre);
    }


  return 0;
}
