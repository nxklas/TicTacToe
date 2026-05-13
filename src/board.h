#ifndef TICTACTOE_BOARD_H
#define TICTACTOE_BOARD_H

/**
 * Defines constants for the dimentsions of a TicTacToe board.
 */
enum BoardDimensions {
    /**
     * The width and height of the board.
     */
    BOARD_SIZE = 3,
    /**
     * The total number of cells of the board.
     */
    BOARD_TOTAL_SIZE = BOARD_SIZE * BOARD_SIZE
};

/**
 * Represents a state a cell can accept.
 */
typedef enum CellState {
    /**
     * Cell state for player 0.
     */
    CELL_STATE_O = -1,
    /**
     * Cell state for empty, but initialized cell.
     */
    CELL_STATE_NONE = 0,
    /**
     * Cell state for player X.
     */
    CELL_STATE_X = 1
} CellState;

/**
 * Represents a standard TicTacToe board.
 */
typedef struct Board {
    /**
     * Represents the board.
     */
    CellState cells[BOARD_TOTAL_SIZE];
} Board;

/**
 * @brief Renders the specified board to the standard output.
 * 
 * @param[out] board The pointer to the board to render.
 */
void render_board(const Board* board);

/**
 * @brief Sets a cell at the specified coordinates to a specific state.
 * 
 * Parameters x, y, and state must be in a valid range in order for this function to accept the specified cell state.
 * 
 * @param[in] x The x-coordinate of the cell.
 * @param[in] y The y-coordinate of the cell.
 * @param[in] state The state of the cell to set.
 * @param[out] board The pointer to the board where to set the cell.
 * @return 0 if the cell is set successfully; otherwise, 1.
 */
int set_cell(const int x, const int y, const CellState state, Board* board);

/**
 * @brief Initializes the specified board to its default value.
 * 
 * @param[out] board The pointer to the board to initialize.
 */
void init_board(Board* board);

/**
 * @brief Creates a new board and initializes it.
 * 
 * NOTE: Please free me after use!
 * 
 * @return A pointer to the created board or NULL if no memory could be allocated.
 */
Board* create_board(void);
#endif
