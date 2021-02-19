#include <stdio.h>
#include <stdlib.h>

#include "board.h" // quotes for custom header

int main(void) {
    Board *bptr;
    bptr = (Board *)malloc(sizeof(Board));
    bptr->nrows = 0;
    bptr->ncols = 0;
    
    int steps = 0;
    int wcnt = 0;
    int bcnt = 0;

    set_dim(bptr);
    scanf("%d", &steps);
	initialize_board(bptr);

	for(int i = 0; i < steps; i++)
        update_board(bptr);

    for(int r = 0; r < bptr->nrows; r++) {
            for(int c = 0; c < bptr->ncols; c++) {
                char pos = *(bptr->grid + r * bptr->ncols + c);
                if(pos == 'w')
                    wcnt++;
                else if(pos == 'b')
                    bcnt++;
            }
        }

    // Print new board
    for(int i = 0; i < bptr->nrows * bptr->ncols; i++) {
        if (i % bptr->ncols != 0)
             printf("%c ", *(bptr->grid+i));
        else
            printf("\n%c ", *(bptr->grid+i));
    }

    printf("\nwhite: %d, blue: %d\n", wcnt, bcnt);
        
    free(bptr);
    free(bptr->grid);

    return 0;
}
