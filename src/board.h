#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

enum BoardDimensions {
    BOARD_SIZE = 3,
    BOARD_TOTAL_SIZE = BOARD_SIZE * BOARD_SIZE
};

typedef enum CellState {
    CELL_STATE_O = -1,
    CELL_STATE_NONE = 0,
    CELL_STATE_X = 1
} CellState;

typedef struct Board {
    CellState cells[BOARD_TOTAL_SIZE];
} Board;

void render_board(const Board* board);

void init_board(Board* board);

Board* create_board(void);
#endif
