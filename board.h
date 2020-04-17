#ifndef BOARD_H // make sure to use "ifndef" NOT "ifdef"
#define BOARD_H

// BOARD.H

typedef struct Board {
    int nrows;
    int ncols;
    char *grid;
} Board;

int set_dim(Board *);

int initialize_board(Board *);

void update_board(Board *);


#endif
