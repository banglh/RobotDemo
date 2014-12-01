#include "MapInterface.h"

void mapInit(unsigned int map[N_ROW][N_COL]) {
    int i,j;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            map[i][j] = 0;
        }
    }

    // add information of border walls
    for (j = 0; j < N_COL; j++) {
        // North border
        map[0][j] += NORTH_WALL;

        // South border
        map[N_ROW - 1][j] += SOUTH_WALL;
    }

    for (i = 0; i < N_ROW; i++) {
        // West border
        map[i][0] += WEST_WALL;

        // East border
        map[i][N_COL - 1] += EAST_WALL;
    }
}

void printMap(unsigned int map[N_ROW][N_COL]) {
    int i,j;

    for (i = 0; i < N_ROW; i++) {
        for (j = 0; j < N_COL; j++) {
            printf("%4d", map[i][j]);
        }
        printf("\n");
    }
}
