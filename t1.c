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

void f(void (*)(unsigned int));
int func(int);


int main()
{
  int ****v;
  int ***s;
  int **p;
  int *q = (int*)malloc(sizeof(int));
  int *r = (int*)malloc(sizeof(int));
  *q = 5;
  p = &q;
  s = &p;
  v = &s;
  int c = 0;
  scanf("%d",&c);
  struct Connection *conn = malloc(sizeof(struct Connection));
  struct Connection *pp;
  printf("by dot to reference , %d\n",(*conn).year);
  conn->db = malloc(sizeof(struct Database));
  conn->db->addre = p;
  conn->year = 2015;
  conn->age = (int*)malloc(sizeof(int));
  *(conn->age) =25;

  struct Connection *list[3];
  list[0] = malloc(sizeof(struct Connection));
  list[0]->db = malloc(sizeof(struct Database));
  list[0]->year = 0;

  struct Connection *list2[2][2];
  list2[0][1] = malloc(sizeof(struct Connection));
  list2[0][1]->db = malloc(sizeof(struct Database));
  list2[0][1]->year = 2016;

  if(p){
    **p = func(**p);
    int m = func(**p);
  }

  return 0;
}
