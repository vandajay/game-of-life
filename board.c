#include <stdio.h>
#include <stdlib.h>

#include "board.h"

int set_dim(Board *b) {
    int q = EOF + 1;
	
    for(int i=0; i < 2; i++) {
        if (i == 0) {
            q = scanf("%d", &b->nrows);
        }
        if (i == 1) {
            q = scanf("%d", &b->ncols);
        }
    }
	
	b->grid = (char *)malloc(b->nrows * b->ncols * sizeof(char));

	for(int i=0; i < b->nrows * b->ncols; i++) {
		*(b->grid+i) = i;
	}
	
	printf("nrows=%d, ncols=%d", b->nrows, b->ncols);

    return q;
}


int initialize_board(Board *b) {
	int q = EOF + 1;
	
    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            q = scanf("%c", b->grid + r * b->ncols + c);
        }
    }
	return q;
}

void update_board(Board *b) { // Better NOT to use prototypes for blank functions...
}
