/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters */
/* DISCLAIMER: This solution assumes that input lines are less than MAX_LENGTH characters, because the task does not specify if and how I should hadle longer lines */

#include <stdio.h>

#define MAX_LENGTH 1000    /* maximum input line size */
#define PRINT_FROM 80      /* longer lines are printed */
#define MAX_LINES  100     /* maximum lines (PRINT_FROM + 1 characters) storage */

int getline_custom(char s[], int lim);    /* read a line into s, return length */
void copy(char to[], char from[]);        /* copy 'from' into 'to'; assume to is big enough */

int main()
{
    char cur_line[MAX_LENGTH];    /* current input line */
    int cur_line_length;          /* current input line length */

    char out[MAX_LINES][MAX_LENGTH];    /* storage for lines (PRINT_FROM + 1 characters) to output */
    int out_lines_count = 0;            /* indexer for out[][] lines, also controls overflow */

    while (out_lines_count < MAX_LINES && (cur_line_length = getline_custom(cur_line, MAX_LENGTH)) > 0)
        if (cur_line_length > PRINT_FROM) {
            copy(out[out_lines_count], cur_line);
            ++out_lines_count;
        }
    
    int i;
    for (i = 0; i < out_lines_count; ++i)
        printf("%s", out[i]);
    printf("\n");

    return 0;
}

int getline_custom(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
   int i = 0;

   while ((to[i] = from[i]) != '\0')
       ++i;
}
