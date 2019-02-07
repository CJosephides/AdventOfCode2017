/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "states.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: main <target>\n");
        exit(1);
    }

    int target = atoi(argv[1]);
    int current = 1;
    int x = 0;
    int y = 0;
    int outer_c = 1;
    State direction = west;
    int inner_c = 1; 

    while (current < target) {

        switch (direction) {
            
            case west:
                x += 1;
                inner_c--;
                if (inner_c == 0) {
                    inner_c = outer_c;
                    direction = (direction + 1) % 4;
                }
                break;

            case north:
                y += 1;
                inner_c--;
                if (inner_c == 0) {
                    inner_c = ++outer_c;
                    direction = (direction + 1) % 4;
                }
                break;

            case east:
                x -= 1;
                inner_c--;
                if (inner_c == 0) {
                    inner_c = outer_c;
                    direction = (direction + 1) % 4;
                }
                break;

            case south:
                y -= 1;
                inner_c--;
                if (inner_c == 0) {
                    inner_c = ++outer_c;
                    direction = (direction + 1) % 4;
                }
                break;
        }

        current++;  // next coordinate
    }

    printf("Target is at (x=%d, y=%d). Manhattan distance = %d.\n", x, y, abs(x)+abs(y));
    return 0;
}
