#ifndef BOARD_H // make sure to use "ifndef" NOT "ifdef"
#define BOARD_H

typedef struct Board {
    int nrows;
    int ncols;
    char *grid;
} Board;

void set_dim(Board *);

void initialize_board(Board *);

void update_board(Board *);

#endif
