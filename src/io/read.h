#ifndef TICTACTOE_READ_H
#define TICTACTOE_READ_H

#include "../coordinate.h"

/**
 * @brief Reads a coordinate from standard input and stores it in the specified coordinate struct.
 * 
 * @param[out] coordinate The pointer to the coordinate struct that receives the read value.
 * @return 0 if the input format was valid and the coordinate was successfully written; otherwise, 1.
 */
int read_coordinate(Coordinate* coordinate);

/**
 * @brief Reads the next occoring 32-bit integer value from the specified string.
 * 
 * @param[in] str The pointer to the string to read.
 * @param[in, out] start The pointer to the int that represents the current index of the string (may be altered when this function returns).
 * @param[in] len The length of the string to read.
 * 
 * @return The read number or 0 if no number has been read.
 */
int read_number(const char* str, int* start, const int len);
#endif
