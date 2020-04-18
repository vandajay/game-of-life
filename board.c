#include <stdio.h>
#include <stdlib.h>

#include "board.h"

void set_dim(Board *b) {
    int cnt = 1;
	
    for(int i=0; i < 2; i++) {
        if (cnt % 2 != 0) {
            scanf("%d", &b->nrows);
            cnt++;
        } else {
            scanf("%d", &b->ncols);
        }
    }
    
    b->grid = (char *)malloc(b->nrows * b->ncols * sizeof(char));

    for(int i=0; i < b->nrows * b->ncols; i++) {
		*(b->grid+i) = i;
    }
}


void initialize_board(Board *b) {
    char ch = 'x';

    for (int r = 0; r < b->nrows; r++) {
        for (int c = 0; c < b->ncols; c++) {
            scanf("%c", &ch);
            while (ch == ' ' || ch == '\n') {
                scanf("%c", &ch);
            }
            *(b->grid + r * b->ncols + c) = ch;
        }
    }
}

void update_board(Board *b) { // Better NOT to use prototypes for blank functions...
    Board *temp;
    temp = (Board *)malloc(sizeof(Board));
    temp->nrows = b->nrows;
    temp->ncols = b->ncols;
    temp->grid = (char *)malloc(b->nrows * b->ncols * sizeof(char));

    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            *(temp->grid + r * temp->ncols + c) = '.'; 
        }
    }

    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            int wcnt = 0;
            int bcnt = 0;
            int xcnt = 0;
            
            int minrow = ((r-1) % b->nrows) < 0 ? (((r-1) % b->nrows) + b->nrows) : ((r-1) % b->nrows);
            int row = ((r) % b->nrows) < 0 ? (((r) % b->nrows) + b->nrows) : ((r) % b->nrows);
            int plusrow = ((r+1) % b->nrows) < 0 ? (((r+1) % b->nrows) + b->nrows) : ((r+1) % b->nrows);

            int mincol = ((c-1) % b->ncols) < 0 ? (((c-1) % b->ncols) + b->ncols) : ((c-1) % b->ncols);
            int col = ((c) % b->ncols) < 0 ? (((c) % b->ncols) + b->ncols) : ((c) % b->ncols);
            int pluscol = ((c+1) % b->ncols) < 0 ? (((c+1) % b->ncols) + b->ncols) : ((c+1) % b->ncols);

            printf("minrow=%d, row=%d, plusrow=%d\n", minrow, row, plusrow);
            printf("mincol=%d, col=%d, pluscol=%d\n\n", mincol, col, pluscol);


            char pos = *(b->grid + r * b->ncols + c);

            char nw = *(b->grid + (minrow) * b->ncols + (mincol));
            char n = *(b->grid + (minrow) * b->ncols + (col));
            char ne = *(b->grid + (minrow) * b->ncols + (pluscol));
            char w = *(b->grid + (row) * b->ncols + (mincol));
            char e = *(b->grid + (row) * b->ncols + (pluscol));
            char sw = *(b->grid + (plusrow) * b->ncols + (mincol));
            char s = *(b->grid + (plusrow) * b->ncols + (col));
            char se = *(b->grid + (plusrow) * b->ncols + (pluscol));

            printf("nw=%c, n=%c, ne=%c\n", nw, n, ne);
            printf("w=%c, e=%c\n", w, e);
            printf("sw=%c, s=%c, se=%c\n\n", sw, s, se);



            // Count types surrounding position
            //
            // row - 1, col - 1
            // NW
            if(nw == 'w') {
                wcnt++;
            } else if (nw == 'b') {
                bcnt++;
            } else {
                xcnt++;
            }

            // row - 1, col
            // N
            if(n == 'w') {
                wcnt++;
            } else if (n == 'b') {
                bcnt++;
            } else {
                xcnt++;
            }

            // row - 1, col + 1
            // NE
            if(ne == 'w') {
                wcnt++;
            } else if (ne == 'b') {
                bcnt++;
            } else {
                xcnt++;
            }

            // row, col - 1
            // W
            if(w == 'w') {
                wcnt++;
            } else if (w == 'b') {
                bcnt++;
            } else {
                xcnt++;
            }

            // row, col + 1
            // E
            if(e == 'w') {
                wcnt++;
            } else if (e == 'b') {
                bcnt++;
            } else {
                xcnt++;
            }

            // row + 1, col - 1
            // SW
            if(sw == 'w') {
                wcnt++;
            } else if (sw == 'b') {
                bcnt++;
            } else {
                xcnt++;
            }

            // row + 1, col
            // S
            if(s == 'w') {
                wcnt++;
            } else if (s == 'b') {
                bcnt++;
            } else {
                xcnt++;
            }

            // row + 1, col + 1
            // SE
            if(se == 'w') {
                wcnt++;
            } else if (se == 'b') {
                bcnt++;
            } else {
                xcnt++;
            }

            // Check for Overpopulation for white and blue
            if(pos == 'w' || pos == 'b') {
                if((wcnt+bcnt) > 3) {
                    *(temp->grid + r * temp->ncols + c) = 'x';
                } else if((wcnt+bcnt) < 2) {
                    *(temp->grid + r * temp->ncols + c) = 'x';
                } else {
                    *(temp->grid + r * temp->ncols + c) = pos;
                }
            }

            // Check for Birth
            else if (pos == 'x') { 
                if (wcnt > bcnt && wcnt + bcnt == 3) {
                    *(temp->grid + r * temp->ncols + c) = 'w';
                } else if (bcnt > wcnt && wcnt + bcnt == 3) {
                    *(temp->grid + r * temp->ncols + c) = 'b';
                } else {
                    *(temp->grid + r * temp->ncols + c) = 'x';
                }
            }
        }
    }
    // Overwrite original board
    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            *(b->grid + r * b->ncols + c) = *(temp->grid + r * temp->ncols + c);
        }
    }
    free(temp);
    free(temp->grid);
}
