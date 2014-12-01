#include <stdio.h>
#include <stdlib.h>
#include "MapInterface.h"

// an 2D array for encoding map information
unsigned int map[N_ROW][N_COL];

int main()
{
    // initialize map
    mapInit(map);

    printMap(map);

    return 0;
}
