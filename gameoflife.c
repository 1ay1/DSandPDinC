#include "gameoflife.h"

int main()
{
  Grid map;
  Grid newMap;
  initialize(map);
  writeMap(map);
  printf("This is the initial config you have chosen.\n"
	 "Press <Enter> to continue.\n");
  while(getchar() != '\n');
  do {
    for( int i = 1; i <= MAXROW; i++)
      {
	for(int j = 1; j <= MAXCOL; j++)
	  {
	    switch(neighCount(map, i, j))
	      {
	      case 0:
	      case 1:
		newMap[i][j] = DEAD;
		break;
	      case 2:
		newMap[i][j] = map[i][j];
		break;
	      case 3:
		newMap[i][j] = ALIVE;
		break;
	      case 4:
	      case 5:
	      case 6:
	      case 7:
	      case 8:
		newMap[i][j] = DEAD;
		break;
	      }
	  }
      }
    CopyMap(map, newMap);
    writeMap(map);
    printf("Do you want another generation?\n");
  } while (userSaysYes());
  return 0;
}
