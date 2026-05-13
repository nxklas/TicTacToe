#include <stdlib.h>
#include "board.h"

int main(void) {
    Board* board = create_board();

    if (!board)
        return 1;

    set_cell(1, 1, CELL_STATE_O, board);
    set_cell(1, 2, CELL_STATE_X, board);
    render_board(board);
    free(board);
}
