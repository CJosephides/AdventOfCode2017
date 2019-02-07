/* linked.h */

typedef struct linked {
    int x, y, value;
    struct linked *next;
} Linked, *LinkedPtr;


LinkedPtr new_item(int x, int y, int value);
LinkedPtr append(int x, int y, int value, const LinkedPtr root);
LinkedPtr get(int x, int y, const LinkedPtr root);
