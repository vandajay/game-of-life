#ifndef BOARD_H // make sure to use "ifndef" NOT "ifdef"
#define BOARD_H

// BOARD.H

typedef struct Board {
    int nrows;
    int ncols;
    char *grid;
} Board;

Board* update_board(Board *);

#endif
