#include <stdio.h>
#include <stdlib.h>

#include "board.h" // quotes for custom header

#define DIM 2
#define TIMES 1
// CONWAY.C

int main(void) {
    Board *bptr;
    bptr = (Board *)malloc(sizeof(Board));
    bptr->nrows = 0;
    bptr->ncols= 0;
    bptr->grid = (char *)malloc(sizeof(char));
    
    int q = EOF + 1;
    int steps = 0;

    while (q != EOF) {
        for(int i=0; i < DIM; i++) {
            if (i == 0) {
                scanf("%d", &bptr->nrows);
            }
            if (i == 1) {
                scanf("%d", &bptr->ncols);
            }
        }

        bptr->grid = (char *)malloc(bptr->nrows*bptr->ncols*sizeof(char));

        scanf("%d", &steps);

        for(int r=0; r < bptr->nrows; r++) {
            // fill row r
            for(int c=0; c < bptr->ncols; c++) {
                // fill row r, col c
            }
        }
    }

    printf("rows=%d cols=%d", bptr->nrows, bptr->ncols);

    update_board(bptr);

    free(bptr);
    free(bptr->grid);
}
