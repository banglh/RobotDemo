#include "MapInterface.h"

void mapInit(unsigned int map[N_ROW][N_COL]) {
    int i,j;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            map[i][j] = 0;
            printf("%d\n", map[i][j]);
        }
    }
}
