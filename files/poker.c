#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define true 1
#define false 0

int Num = 4;

struct Poker {
    char *name;
    int num ;
};

/* char *strdup(char *name) */
/* { */
/*   char *p = malloc(sizeof(char)); */
/*   Num = Num -1; */
/*   assert(Num >= 0); */
/*   p = name ; */
/*   return p; */
/* } */

struct Poker *Poker_create(char *name, int num)
{
    struct Poker *pn = malloc(sizeof(struct Poker));

    if(pn)
      {
        /* assert */
        Num = Num -1 ;
        assert(Num >= 0);

        pn->name = "ddd";/* strdup(name); */
        /* assert */
        Num = Num -1 ;
        assert(Num >= 0);

        pn->num = num;
        return pn;
      }
    else
      {
        printf("Error: no space for allocation\n");
        exit(1);
      }
}

void Poker_destroy(struct Poker *pn)
{
  if(pn)
    {

    free(pn->name);

    Num = Num + 1;

    free(pn);

    Num = Num + 1;
    }
  /* else */
  /*   { */
  /*     printf("Error: pointer is null \n"); */
  /*      exit(1); */
  /*   } */

}

void Poker_print(struct Poker *pn)
{
    switch (pn->num)
    {
    case 2: case 3: case 4: case 5:
    case 6: case 7: case 8:
    case 9: case 10: printf("%s, %d\n",pn->name, pn->num)  ;break;

    case 1: printf("%s, %s\n",pn->name,"A" ) ;break;
    case 11: printf("%s, %s\n", pn->name,"J") ;break;
    case 12: printf("%s, %s\n",pn->name, "Q") ;break;
    case 13: printf("%s, %s\n", pn->name, "K") ;break;
    default :printf("%s, %d\n",pn->name,1) ;break;
    }
}

void result(struct Poker *fst, struct Poker *sec)
{
   if(fst->num > sec->num)
            {
               printf("winner: player1,   ");
               Poker_print(fst);
               printf("loser: player2,    ");
               Poker_print(sec);
            }
          else if(fst->num < sec->num)
            {
               printf("winner: player2,   ");
               Poker_print(sec);
               printf("loser: player1,    ");
               Poker_print(fst);
            }
          else
            {
              printf("player1 and player2 drew\n");
              Poker_print(fst);
              Poker_print(sec);
            }
}

int main(int argc, char *argv[])
{
  struct Poker *fst ;
  struct Poker *sec;
  char *pname[] = {"Diamond","Spade","Heart","Club"};
  int play ;

 l1:
  printf("Do you want to play poker? 1 is Yes, to start\n");
  scanf("%d", &play);

  if(play > 0)
    {
      fst = Poker_create(pname[rand()%4], (rand()%13) + 1);
      sec = Poker_create(pname[rand()%4], (rand()%13) + 1);

      result(fst,sec);

      Poker_destroy(sec);
      Poker_destroy(fst);
    }
  else
    {
      printf("see you next time\n");
      exit(0);
    }
  goto l1;
  return 1;
}
