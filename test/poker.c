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

struct Poker *Poker_create(char *name, int num)
{
    struct Poker *pn = malloc(sizeof(struct Poker));

    assert(pn != NULL);

    /* assert */
    Num = Num -1 ;
    assert(Num >= 0);

    pn->name = strdup(name);
    /* assert */
    Num = Num -1 ;
    assert(Num >= 0);

    pn->num = num;
    return pn;
}

void Poker_destroy(struct Poker *pn)
{
    assert(pn != NULL);

    free(pn->name);
    /* free */
    Num = Num + 1;

    free(pn);
    /* free */
    Num = Num + 1;

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

int main(int argc, char *argv[])
{
  struct Poker *fst ;
  struct Poker *sec;
  char *pname[] = {"Diamond","Spade","Heart","Club"};
  printf("Do you have time to play poker? 1 is Yes, to start\n");
  int play ;
  scanf("%d", &play);

  if(play > 0)
    {
      fst = Poker_create(pname[rand()%4], (rand()%13) + 1);
      sec = Poker_create(pname[rand()%4], (rand()%13) + 1);
    }

  /*some statements*/

  Poker_print(fst);
  Poker_print(sec);

  /* some statements */

  if(play > 0)
    {
      Poker_destroy(fst);
      Poker_destroy(sec);
    }

  return 1;
}
