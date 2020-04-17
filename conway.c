#include <stdio.h>
#include <stdlib.h>

#include "board.h" // quotes for custom header

// CONWAY.C

int main(void) {
    Board *bptr;
    bptr = (Board *)malloc(sizeof(Board));
    bptr->nrows = 0;
    bptr->ncols= 0;
    
    int q = EOF + 1;
    int steps = 0;

    int wcnt = 0;
    int bcnt = 0;

    do {
        wcnt = 0;
        wcnt = 0;

        printf("\nBEGIN LOOP\n");

        q = set_dim(bptr);
        printf("rows=%d cols=%d\n", bptr->nrows, bptr->ncols);


        if (q != EOF) {
            q = scanf("%d", &steps);
	        printf("steps=%d\n", steps);
        }

	    if (q != EOF) {
		    q = initialize_board(bptr);
            printf("START grid=%s\n", bptr->grid);
        }

        if (q != EOF && steps != 0) {
		    for(int i = 0; i < steps; i++)
                update_board(bptr);
            printf("NEW grid=%s\n", bptr->grid);
        } 
        else {
            q = EOF;
        }

        

        if (q != EOF) {
            for(int r = 0; r < bptr->nrows; r++) {
                for(int c = 0; c < bptr->ncols; c++) {
                    if(*(bptr->grid + r * bptr->ncols + c) == 'w')
                        wcnt++;
                    else if(*(bptr->grid + r * bptr->ncols + c) == 'b')
                        bcnt++;
                }
            }
        }

       printf("white: %d, blue: %d", wcnt, bcnt); 
    } while (q != EOF);

    free(bptr);
    free(bptr->grid);

    printf("END CONWAY.C\n");
    return 0;
}
