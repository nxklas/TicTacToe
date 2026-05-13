#include <stdio.h>
#include <stdlib.h>
#include "read.h"

int read_coordinate(Coordinate* coordinate) {
    #define MAX_CHARS (10)

    if (!coordinate) {
        printf("No memory could be allocated to store the coordinates in.\n");
        return 1;
    }

    char user_input[MAX_CHARS];
    int number_count = 0;
    int position = 0;

    fgets(user_input, sizeof(user_input), stdin);

    while (position < MAX_CHARS) {
        char c = user_input[position];

        if (c > 47 && c < 58) {
            int num = read_number(user_input, &position, MAX_CHARS);

            if (number_count == 0) {
                coordinate->x = num;
                ++number_count;
            }
            else if (number_count == 1) {
                coordinate->y = num;
                ++number_count;
            }
            else {
                printf("Too many numbers in input.\n");
                return 1;
            }
        }
        else if (c == '\0')
            break;
        else if (c != ' ') {
            printf("Illegal char in input: '%c'.\n", c);
            return 1;
        }

        ++position;
    }

    if (number_count != 2) {
        printf("Expected 2 numbers in input, separated by a whitespace.\n");
        return 1;
    }

    return 0;
}

int read_number(const char* str, int* start, const int len) {
    int res = 0;

    for (; *start < len; (*start)++) {
        char c = str[*start];

        if (c > 47 && c < 58)
            res = res * 10 + c - '0';
        else
            break;
    }

    return res;
}
