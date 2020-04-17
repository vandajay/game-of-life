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
    
    b->grid = (char *)malloc(b->nrows * b->ncols * sizeof(char));

    for(int i=0; i < b->nrows * b->ncols; i++) {
		*(b->grid+i) = i;
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

void update_board(Board *b) { // Better NOT to use prototypes for blank functions...

    char temp[b->nrows][b->ncols];

    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            temp[r][c] = '.';
        }
    }

    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            printf("%c", *(b->grid + r * b->ncols + c));
        }
    }


    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            printf("\n[%d][%d]\n", r, c);
            int wcnt = 0;
            int bcnt = 0;
            int xcnt = 0;

            int mrow = 0;
            int mcol = 0;


            // printf("-1 mod 5= %d\n", (-1/5)*5+(-1%5));


            // Count types surrounding position
            //
            // row - 1, col - 1
            mrow = ((r-1) % b->nrows) < 0 ? (((r-1) % b->nrows) + b->nrows) : ((r-1) % b->nrows);
            mcol = ((c-1) % b->ncols) < 0 ? (((c-1) % b->ncols) + b->ncols) : ((c-1) % b->ncols);
            if(*(b->grid + (mrow) * b->ncols + (mcol)) == 'w') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                wcnt++;
            } else if (*(b->grid + (mrow) * b->ncols + (mcol)) == 'b') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                xcnt++;
            }

            // row - 1, col
            mrow = ((r-1) % b->nrows) < 0 ? (((r-1) % b->nrows) + b->nrows) : ((r-1) % b->nrows);
            mcol = ((c) % b->ncols) < 0 ? (((c) % b->ncols) + b->ncols) : ((c) % b->ncols);
            if(*(b->grid + (mrow) * b->ncols + (mcol)) == 'w') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                wcnt++;
            } else if (*(b->grid + (mrow) * b->ncols + (mcol)) == 'b') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                xcnt++;
            }

            // row - 1, col + 1
            mrow = ((r-1) % b->nrows) < 0 ? (((r-1) % b->nrows) + b->nrows) : ((r-1) % b->nrows);
            mcol = ((c+1) % b->ncols) < 0 ? (((c+1) % b->ncols) + b->ncols) : ((c+1) % b->ncols);
            if(*(b->grid + (mrow) * b->ncols + (mcol)) == 'w') {
                printf("%c,", *(b->grid + (mrow) * b->ncols + (mcol)));
                wcnt++;
            } else if (*(b->grid + (mrow) * b->ncols + (mcol)) == 'b') {
                printf("%c,", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                bcnt++;
            } else {
                printf("%c,", *(b->grid + (mrow) * b->ncols + (mcol)));
                xcnt++;
            }

            // row, col - 1
            mrow = ((r) % b->nrows) < 0 ? (((r) % b->nrows) + b->nrows) : ((r) % b->nrows);
            mcol = ((c-1) % b->ncols) < 0 ? (((c-1) % b->ncols) + b->ncols) : ((c-1) % b->ncols);
            if(*(b->grid + (mrow) * b->ncols + (mcol)) == 'w') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                wcnt++;
            } else if (*(b->grid + (mrow) * b->ncols + (mcol)) == 'b') {
                printf("%c", *(b->grid + ((r) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                xcnt++;
            }

            // row, col + 1
            mrow = ((r) % b->nrows) < 0 ? (((r) % b->nrows) + b->nrows) : ((r) % b->nrows);
            mcol = ((c+1) % b->ncols) < 0 ? (((c+1) % b->ncols) + b->ncols) : ((c+1) % b->ncols);
            if(*(b->grid + (mrow) * b->ncols + (mcol)) == 'w') {
                printf("%c,", *(b->grid + (mrow) * b->ncols + (mcol)));
                wcnt++;
            } else if (*(b->grid + (mrow) * b->ncols + (mcol)) == 'b') {
                printf("%c,", *(b->grid + (mrow) * b->ncols + (mcol)));
                bcnt++;
            } else {
                printf("%c,", *(b->grid + (mrow) * b->ncols + (mcol)));
                xcnt++;
            }

            // row + 1, col - 1
            mrow = ((r+1) % b->nrows) < 0 ? (((r+1) % b->nrows) + b->nrows) : ((r+1) % b->nrows);
            mcol = ((c-1) % b->ncols) < 0 ? (((c-1) % b->ncols) + b->ncols) : ((c-1) % b->ncols);
            if(*(b->grid + (mrow) * b->ncols + (mcol)) == 'w') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                wcnt++;
            } else if (*(b->grid + (mrow) * b->ncols + (mcol)) == 'b') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                xcnt++;
            }

            // row + 1, col
            mrow = ((r+1) % b->nrows) < 0 ? (((r+1) % b->nrows) + b->nrows) : ((r+1) % b->nrows);
            mcol = ((c) % b->ncols) < 0 ? (((c) % b->ncols) + b->ncols) : ((c) % b->ncols);
            if(*(b->grid + (mrow) * b->ncols + (mcol)) == 'w') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                wcnt++;
            } else if (*(b->grid + (mrow) * b->ncols + (mcol)) == 'b') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                xcnt++;
            }

            // row + 1, col + 1
            mrow = ((r+1) % b->nrows) < 0 ? (((r+1) % b->nrows) + b->nrows) : ((r+1) % b->nrows);
            mcol = ((c+1) % b->ncols) < 0 ? (((c+1) % b->ncols) + b->ncols) : ((c+1) % b->ncols);
            if(*(b->grid + (mrow) * b->ncols + (mcol)) == 'w') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                wcnt++;
            } else if (*(b->grid + (mrow) * b->ncols + (mcol)) == 'b') {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + (mrow) * b->ncols + (mcol)));
                xcnt++;
            }

            printf("\nw[%d] b[%d] x[%d]\n", wcnt, bcnt, xcnt);

            // Check for Overpopulation for white and blue
            if(*(b->grid + r * b->ncols + c) == 'w' || *(b->grid + r * b->ncols + c) == 'b') {
                if((wcnt+bcnt) > 3) {
                    temp[r][c] = 'x';
                } else if((wcnt+bcnt) < 2) {
                    temp[r][c] = 'x';
                } else {
                    temp[r][c] = *(b->grid + r * b->ncols + c);
                }
            } else if (*(b->grid + r * b->ncols + c) == 'x') { // Check for Birth
                if (wcnt == 3 && wcnt + bcnt < 4) {
                    temp[r][c] = 'w';
                } else if (bcnt == 3 && wcnt + bcnt < 4) {
                    temp[r][c] = 'b';
                } else {
                    temp[r][c] = 'x';
                }
            }
            printf("%c->%c\n", *(b->grid + r * b->ncols + c), temp[r][c]);
        }
    }

    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            *(b->grid + r * b->ncols + c) = temp[r][c];
        }
    }

    printf("**END updating board**\n");
}
