#include<stdio.h>
#include<stdlib.h>

#include"board.h" // quotes for custom header

int main(void) {
    Board *b;
    b = (Board *)malloc(sizeof(Board));
    b->nrows = 5;
    b->ncols = 4;
    b->grid = (char *)malloc(b.nrows*b.ncols*(sizeof(char)); // have to malloc pointer within struct
	
	update_board;
	



	free(b->grid);
    return 0;
}
