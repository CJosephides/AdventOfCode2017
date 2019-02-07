/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "states.h"
#include "linked.h"

/* Calculate the value of cell at (x, y). */
int calculate_value(int x, int y, const LinkedPtr head)
{
    LinkedPtr neighbor;
    int i, j;
    int value = 0;
    for (i = -1; i < 2; i++) {
        for (j = -1; j < 2; j++) {
            if ((i == 0)  && (j == 0))
                continue;

            if ((neighbor = get(x + i, y + j, head)) != NULL) {
                value += neighbor->value;
            }
        }
    }
    return value;
}

int main(int argc, char **argv)
{

    if (argc != 2) {
        printf("Usage: main <target>\n");
        exit(1);
    }

    int target = atoi(argv[1]);
    int x = 0;
    int y = 0;
    int outer_c = 1;
    State direction = west;
    int inner_c = 1; 

    /* Our linked list head. */
    LinkedPtr head = new_item(x, y, 1);
    LinkedPtr current = head;

    while (current->value <= target) {

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

        current = append(x, y, calculate_value(x, y, head), head); 
    }

    printf("First value larger than %d: %d.\n", target, current->value);
    return 0;
}
