#include <stdio.h>
#include <stdlib.h>

#include "board.h" // quotes for custom header

#define DIM 2
#define TIMES 1
// CONWAY.C

void count_colors(Board *);

int main(void) {
    Board *bptr;
    bptr = (Board *)malloc(sizeof(Board));
    bptr->nrows = 0;
    bptr->ncols= 0;
    
    int q = EOF + 1;
    int steps = 0;

    do {
        set_dim(bptr);
        printf("rows=%d cols=%d", bptr->nrows, bptr->ncols);

		initialize_board(bptr);
		
        scanf("%d", &steps);
		
		for(int i = 0; i < steps; i++) {
            update_board(bptr);
        }

        count_colors(bptr);
        
    } while (q != EOF);




    free(bptr);
    free(bptr->grid);
}

void count_colors(Board *b) {
}
