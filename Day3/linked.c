/* linked.c */
#ifndef _LINKED_H
#define _LINKED_H

#include <stdlib.h>
#include "linked.h"

/* Create a new linked list item. */
LinkedPtr new_item(int x, int y, int value)
{
    LinkedPtr new = malloc(sizeof(LinkedPtr));
    new->x = x;
    new->y = y;
    new->value = value;
    new->next = NULL;

    return new;
}

/* Append item to linked list starting at root. */
LinkedPtr append(int x, int y, int value, const LinkedPtr root)
{
    LinkedPtr current = root;
    while (current->next != NULL)
        current = current->next;

    LinkedPtr new = new_item(x, y, value); 
    current->next = new;

    return new;
}

/* Retrieve item with x, y coordinates from linked list
 * starting at root. */
LinkedPtr get(int x, int y, const LinkedPtr root)
{
    LinkedPtr current = root;
    while (current != NULL && (current->x != x || current->y != y))
        current = current->next;

    return current;
}

#endif
