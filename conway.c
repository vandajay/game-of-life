#include <stdio.h>
#include <stdlib.h>

#include "board.h" // quotes for custom header

#define DIM 2
#define TIMES 1
// CONWAY.C

int count_colors(Board *);

int main(void) {
    Board *bptr;
    bptr = (Board *)malloc(sizeof(Board));
    bptr->nrows = 0;
    bptr->ncols= 0;
    
    int q = EOF + 1;
    int steps = 0;

    do {
        printf("\nBEGIN LOOP\n");
        q = set_dim(bptr);
        printf("q=%d\n", q);
        printf("rows=%d cols=%d\n", bptr->nrows, bptr->ncols);

        bptr->grid = (char *)malloc(bptr->nrows * bptr->ncols * sizeof(char));

	    for(int i=0; i < bptr->nrows * bptr->ncols; i++) {
		    *(bptr->grid+i) = i;
    	}

        printf("EOF=%d\n", EOF);
        if (q != EOF) {
            q = scanf("%d", &steps);
        }

	    printf("steps=%d\n", steps);
	    
		q = initialize_board(bptr);

        printf("%s\n", bptr->grid);

//        if (q != EOF) {
//            if (steps != 0) {
//                printf("**updating board**\n");
//		        for(int i = 0; i < steps; i++) {
//                    update_board(bptr);
//                }
//            } else {
//                q = EOF;
//            }
//        }

//        if (q != EOF) {
//            q = count_colors(bptr);
//        }
       printf("\nEND LOOP\n"); 
    } while (q != EOF);




    free(bptr);
    free(bptr->grid);

    printf("END CONWAY.C\n");
    return 0;
}

int count_colors(Board *b) {
    return 0;
}
