#include <stdlib.h>
#include "board.h"

int main(void) {
    Board* board = create_board();
    if (!board)
        return 1;
    render_board(board);
    free(board);
}
