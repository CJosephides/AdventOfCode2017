/* linked_tests.c */
#include <stdlib.h>
#include <stdio.h>
#include "linked.h"

int main(int argc, char **argv)
{
    LinkedPtr head = malloc(sizeof(LinkedPtr));
    head->x = 0;
    head->y = 0;
    head->value = 0;
    head->next = NULL;

    printf("Created head of linked list.");
    printf(" x = %d, y = %d.\n", head->x, head->y);

    LinkedPtr tail = append(1, 1, 42, head);

    printf("Created new item in linked list.");
    printf(" x = %d, y = %d.\n", tail->x, tail->y);

}
