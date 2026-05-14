#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "coordinate.h"
#include "io/ansi_codes.h"
#include "io/read.h"

int change_player(CellState* state) {
    if (*state == CELL_STATE_X) {
        *state = CELL_STATE_O;
        return 0;
    }
    else if (*state == CELL_STATE_O) {
        *state = CELL_STATE_X;
        return 0;
    }

    printf("state must be either %d or %d (actual: %d).\n", CELL_STATE_X, CELL_STATE_O, *state);
    return 1;
}

void request_set_cell(Coordinate* coord, const CellState player, Board* board) {
    printf("Please enter\n");

    while (1) {
        if (!read_coordinate(coord))
            break;

        printf("Please enter valid coords in this format: int_x int_y\n");
    }

    while (1) {
        if (!set_cell(coord->x, coord->y, player, board))
            break;

        request_set_cell(coord, player, board);
        break;
    }
}

int main(void) {
    Board* board = create_board();
    CellState player = CELL_STATE_O;

    if (!board)
        return 1;

    while (1) {
        if (player == CELL_STATE_O)
            printf("%sPlayer O's turn.\n", CLEAR_SCREEN_HOME);
        else
            printf("%sPlayer X's turn.\n", CLEAR_SCREEN_HOME);

        render_board(board);
        Coordinate coord;
        request_set_cell(&coord, player, board);
        CellState winner = check_winner(board);

        if (winner == CELL_STATE_O) {
            printf("Player O wins!\n");
            break;
        }
        else if (winner == CELL_STATE_X) {
            printf("Player X wins!\n");
            break;
        }
        else if (is_board_full(board)) {
            printf("A draw...\n");
            break;
        }
        else
            change_player(&player);
    }

    render_board(board);
    free(board);
    return 0;
}
