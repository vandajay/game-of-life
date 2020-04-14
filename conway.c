#include <stdio.h>
#include <stdlib.h>

#include "board.h" // quotes for custom header

// CONWAY.C

int main(void) {
    Board *bptr;
    bptr = (Board *)malloc(sizeof(Board));
    bptr->nrows = 5;
    bptr->ncols= 4;
    bptr->grid = (char *)malloc(sizeof(char));

    update_board(bptr);

    free(bptr);
    free(bptr->grid);
}
