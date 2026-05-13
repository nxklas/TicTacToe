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
