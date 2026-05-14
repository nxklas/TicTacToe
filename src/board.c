#include <stdio.h>
#include <stdlib.h>
#include "board.h"

void render_board(const Board* board) {
    #define STR_LEN (BOARD_SIZE * ((BOARD_SIZE * 4) - 2))
    char str[STR_LEN + 1];
    int str_i = 0;

    for (int i = 0; i < BOARD_TOTAL_SIZE; i++) {
        const CellState state = board->cells[i];

        if (state == CELL_STATE_X)
            str[str_i++] = 'X';
        else if (state == CELL_STATE_O)
            str[str_i++] = 'O';
        else
            str[str_i++] = ' ';

        if ((i + 1) % BOARD_SIZE == 0) {
            str[str_i++] = '\n';
            continue;
        }

        str[str_i++] = ' ';
        str[str_i++] = '|';
        str[str_i++] = ' ';
    }

    str[str_i] = '\0';
    printf("%s", str);
}

CellState check_winner(const Board* board) {
    for (int y = 0; y < BOARD_SIZE; y++) {
        int c = 0;

        for (int x = 0; x < BOARD_SIZE; x++) {
            CellState state = board->cells[y * BOARD_SIZE + x];
            c += state;
        }

        if (c == BOARD_SIZE)
            return CELL_STATE_X;
        else if (c == -BOARD_SIZE)
            return CELL_STATE_O;
    }

    for (int x = 0; x < BOARD_SIZE; x++) {
        int c = 0;

        for (int y = 0; y < BOARD_SIZE; y++) {
            CellState state = board->cells[y * BOARD_SIZE + x];
            c += state;
        }

        if (c == BOARD_SIZE)
            return CELL_STATE_X;
        else if (c == -BOARD_SIZE)
            return CELL_STATE_O;
    }

    int c = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        CellState state = board->cells[i * BOARD_SIZE + i];
        c += state;
    }

    if (c == BOARD_SIZE)
        return CELL_STATE_X;
    else if (c == -BOARD_SIZE)
        return CELL_STATE_O;

    c = 0;
    int y = BOARD_SIZE - 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        CellState state = board->cells[(y - i) * BOARD_SIZE + i];
        c += state;
    }

    if (c == BOARD_SIZE)
        return CELL_STATE_X;
    else if (c == -BOARD_SIZE)
        return CELL_STATE_O;

    return CELL_STATE_NONE;
}

bool is_board_full(const Board* board) {
    for (int i = 0; i < BOARD_TOTAL_SIZE; i++)
        if (board->cells[i] == CELL_STATE_NONE)
            return false;
    return true;
}

int set_cell(const int x, const int y, const CellState state, Board* board) {
    if (x > -1 && x < BOARD_SIZE && y > -1 && y < BOARD_SIZE && (state == CELL_STATE_X || state == CELL_STATE_O)) {
        CellState* cell = &board->cells[y * BOARD_SIZE + x];

        if (*cell != CELL_STATE_NONE) {
            printf("The specified cell at x: %d, y: %d was already set.\n", x, y);
            return 1;
        }

        *cell = state;
        return 0;
    }

    printf("x must be between 0 and %d (actual: %d), y must be between 0 and %d (actual: %d), "
        "and state must be either %d or %d (actual: %d).\n", BOARD_SIZE-1, x, BOARD_SIZE-1, y, CELL_STATE_X, CELL_STATE_O, state);
    return 1;
}

void init_board(Board* board) {
    for (int i = 0; i < BOARD_TOTAL_SIZE; i++)
        board->cells[i] = CELL_STATE_NONE;
}

Board* create_board(void) {
    Board* board = malloc(sizeof(Board));

    if (!board) {
        printf("No memory could be allocated to store the board in.\n");
        return NULL;
    }

    init_board(board);
    return board;
}
