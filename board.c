#include <stdio.h>
#include <stdlib.h>

#include "board.h"

int set_dim(Board *b) {
    printf("SET DIM\n");
    int q = EOF + 1;
    int cnt = 1;
	
    for(int i=0; i < 2; i++) {
        if (cnt % 2 != 0) {
            q = scanf("%d", &b->nrows);
            cnt++;
        } else {
            q = scanf("%d", &b->ncols);
        }
        printf("x=%d y=%d\n", b->nrows, b->ncols);
    }

	printf("SET DIM END\n");
    return q;
}


int initialize_board(Board *b) {
    printf("INITIALIZE BOARD\n");
	int q = EOF + 1;

    char ch = 'x';

    for (int r = 0; r < b->nrows; r++) {
        for (int c = 0; c < b->ncols; c++) {
            q = scanf("%c", &ch);
            while (ch == ' ' || ch == '\n') {
                q = scanf("%c", &ch);
            }
            *(b->grid + r * b->ncols + c) = ch;
        }
    }

    printf("END INITIALIZE BOARD\n");
    return q;
}

//void update_board(Board *b) { // Better NOT to use prototypes for blank functions...
//}
