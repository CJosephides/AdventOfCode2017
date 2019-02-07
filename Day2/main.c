/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIGINT 10000
#define MAXLINE 1000

int main(int argc, char **argv)
{

    if (argc != 3) {
        printf("Usage: main <filename> <n_lines>\n");
        exit(1);
    }

    /* Allocate memory for the lines. */
    int n_lines = atoi(argv[2]);
    int *lines[n_lines];

    /* Read file line-by-line. */
    FILE *fp = fopen(argv[1], "r");
    char line_buffer[MAXLINE];
    int int_buffer[MAXLINE];
    int i, line_len, line_i = 0;

    /* Keep the differences (between the max and min element of each line). */
    int line_max, line_min, differences[n_lines], d_sum = 0;
    int div_sum = 0;

    while (fgets(line_buffer, MAXLINE, fp) != NULL) {
        /* Tokenize string to integers delimited by whitespace. */

        /* First pass to determine line "length". */
        char *token;
        line_len  = 0;

        token = strtok(line_buffer, "\t");
        while (token != NULL) {
            int_buffer[line_len++] = atoi(token);
            token = strtok(NULL, "\t");
        }

        /* Keep line on the heap.
         * We also calculate the max--min difference. */
        line_max = -BIGINT;
        line_min = BIGINT;
        lines[line_i] = calloc(line_len, sizeof(int));
        i = 0;
        for (i = 0; i < line_len; i++) {
            lines[line_i][i] = int_buffer[i];

            if (int_buffer[i] > line_max) {
                line_max = int_buffer[i];
            }
            if (int_buffer[i] < line_min) {
                line_min = int_buffer[i];
            }
        }

        differences[line_i] = line_max - line_min;
        d_sum += differences[line_i];

        /* Find evenly divisible numbers. */
        int j;
        for (i = 0; i < line_len; i++) {
            for (j = 0; j < line_len; j++) {
                if (i == j)
                    continue;
                if (int_buffer[i] % int_buffer[j] == 0) {
                    div_sum += (int_buffer[i] / int_buffer[j]);
                    break;
                }
            }
        }
        /* Next line. */
        line_i++;
    }

    /* Clean up. */
    for (i = 0; i <= n_lines; i++)
        free(lines[i]);
    fclose(fp);

    printf("Sum of differences = %d.\n", d_sum);
    printf("Sum of even divisors = %d.\n", div_sum);
    return 0;
}
