/* main.c */

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{

    if (argc != 2 && argc != 3) {
        printf("Usage: main <filename> [offset]\n");
        exit(1);
    }

    /* Determine input size. */
    char c;
    int input_size = 0;
    FILE *fp = fopen(argv[1], "r");
    while ((c = fgetc(fp)) != EOF) {
        // debug
        putc(c, stdout);
        input_size++;
    }
    input_size--;  // ignore newline

    if (fseek(fp, 0, SEEK_SET) != 0) {
        printf("Something went wrong while rewinding the file.");
        exit(1);
    }

    /* Read input again, this time into memory. */
    int i = 0;
    int series[input_size];
    for (i = 0; i < input_size; i++) {
        c = fgetc(fp);
        series[i] = c - 48;
    }

    /* Finally, calculate captcha sum. */
    int offset, sum = 0;
    if (argc == 3) {
        offset = atoi(argv[2]);
    } else if (argc == 2) {
        offset = input_size / 2;
    }

    for (i = 0; i < input_size; i++) {
        if (series[i] == series[(i + offset) % input_size]) {
            sum += series[i];
        }
    }

    printf("Sum = %d.\n", sum);
    return 0;
}
