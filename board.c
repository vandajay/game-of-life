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
    printf("**updating board**\n");

    char temp[b->nrows][b->ncols];

    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            temp[r][c] = '.';
        }
    }

    for(int r = 0; r < b->nrows; r++) {
        for(int c = 0; c < b->ncols; c++) {
            printf("[%d][%d]\n", r, c);
            int wcnt = 0;
            int bcnt = 0;
            int xcnt = 0; 

            // Count types surrounding position 
            if(*(b->grid + ((r-1) % b->nrows) * b->ncols + ((c-1) % b->ncols)) == 'w') {
                printf("%c", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                wcnt++;
            } else if (*(b->grid + ((r-1) % b->nrows) * b->ncols + ((c-1) % b->ncols)) == 'b') {
                printf("%c", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                xcnt++;
            }

            if(*(b->grid + ((r-1) % b->nrows) * b->ncols + ((c) % b->ncols)) == 'w') {
                printf("%c", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c) % b->ncols)));
                wcnt++;
            } else if (*(b->grid + ((r-1) % b->nrows) * b->ncols + ((c) % b->ncols)) == 'b') {
                printf("%c", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c) % b->ncols)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c) % b->ncols)));
                xcnt++;
            }

            if(*(b->grid + ((r-1) % b->nrows) * b->ncols + ((c+1) % b->ncols)) == 'w') {
                printf("%c,", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                wcnt++;
            } else if (*(b->grid + ((r-1) % b->nrows) * b->ncols + ((c+1) % b->ncols)) == 'b') {
                printf("%c,", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                bcnt++;
            } else {
                printf("%c,", *(b->grid + ((r-1) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                xcnt++;
            }

            if(*(b->grid + ((r) % b->nrows) * b->ncols + ((c-1) % b->ncols)) == 'w') {
                printf("%c", *(b->grid + ((r) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                wcnt++;
            } else if (*(b->grid + ((r) % b->nrows) * b->ncols + ((c+1) % b->ncols)) == 'b') {
                printf("%c", *(b->grid + ((r) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + ((r) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                xcnt++;
            }

            if(*(b->grid + ((r) % b->nrows) * b->ncols + ((c+1) % b->ncols)) == 'w') {
                printf("%c,", *(b->grid + ((r) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                wcnt++;
            } else if (*(b->grid + ((r) % b->nrows) * b->ncols + ((c+1) % b->ncols)) == 'b') {
                printf("%c,", *(b->grid + ((r) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                bcnt++;
            } else {
                printf("%c,", *(b->grid + ((r) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                xcnt++;
            }


            if(*(b->grid + ((r+1) % b->nrows) * b->ncols + ((c-1) % b->ncols)) == 'w') {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                wcnt++;
            } else if (*(b->grid + ((r+1) % b->nrows) * b->ncols + ((c-1) % b->ncols)) == 'b') {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c-1) % b->ncols)));
                xcnt++;
            }

            if(*(b->grid + ((r+1) % b->nrows) * b->ncols + ((c) % b->ncols)) == 'w') {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c) % b->ncols)));
                wcnt++;
            } else if (*(b->grid + ((r+1) % b->nrows) * b->ncols + ((c) % b->ncols)) == 'b') {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c) % b->ncols)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c) % b->ncols)));
                xcnt++;
            }

            if(*(b->grid + ((r+1) % b->nrows) * b->ncols + ((c+1) % b->ncols)) == 'w') {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                wcnt++;
            } else if (*(b->grid + ((r+1) % b->nrows) * b->ncols + ((c+1) % b->ncols)) == 'b') {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
                bcnt++;
            } else {
                printf("%c", *(b->grid + ((r+1) % b->nrows) * b->ncols + ((c+1) % b->ncols)));
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
                if (wcnt == 3) {
                    temp[r][c] = 'w';
                } else if (bcnt == 3) {
                    temp[r][c] = 'b';
                } else {
                    temp[r][c] = 'x';
                }
            }
            printf("%c->%c\n", *(b->grid + r * b->ncols + c), temp[r][c]);
        }
    }
    printf("grid=%s\n", b->grid);
    printf("temp=%s\n", *temp);

    printf("**END updating board**\n");
}
