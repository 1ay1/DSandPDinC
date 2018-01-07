#define MAXROW 20
#define MAXCOL 60
#include "common.h"

typedef enum state {DEAD, ALIVE} State;

typedef State Grid[MAXROW + 2][MAXCOL + 2];

void CopyMap (Grid map, Grid newMap);
Boolean userSaysYes ( void );
void initialize(Grid map);
int neighCount(Grid map, int row, int col);
void writeMap(Grid map);

//dfinitions

void CopyMap(Grid map, Grid newMap)
{
}

Boolean userSaysYes()
{
  while(1) {
    if(getchar() == 'y') return 1;
    else return 0;
  }
}

void initialize(Grid map)
{
 
}

int neighCount(Grid map, int row, int col)
{
  int count = 0;
  for ( int i = row - 1; i <= row+1; i++)
    {
      for ( int j = col - 1; i <= col + 1; j++)
	{
	  if( map[i][j] == ALIVE)
	    count++;
	}
    }
  if( map[row][col] == ALIVE) count--;

  return count;
}

void writeMap(Grid map)
{
}
