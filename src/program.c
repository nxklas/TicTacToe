#include <stdlib.h>
#include "board.h"
#include "coordinate.h"
#include "io/read.h"

int main(void) {
    Board* board = create_board();
    Coordinate coord;

    if (!board)
        return 1;

    render_board(board);
    read_coordinate(&coord);
    set_cell(coord.x, coord.y, CELL_STATE_O, board);
    render_board(board);
    read_coordinate(&coord);
    set_cell(coord.x, coord.y, CELL_STATE_X, board);
    render_board(board);
    free(board);
}
