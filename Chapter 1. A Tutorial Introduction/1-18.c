/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines */
/* DISCLAIMER: This solution assumes that input lines are less than MAX_LENGTH characters, because the task does not specify if and how I should hadle longer lines */

#include <stdio.h>

#define MAX_LENGTH 1000    /* maximum input/output line size */
#define MAX_LINES  100     /* maximum output lines */

int getline_custom(char s[], int lim);               /* read a line into s, return length */
int rm_tr_whitespaces(char s[], int line_length);    /* remove trailing whitespaces, return length */
void copy(char to[], char from[]);                   /* copy 'from' into 'to'; assume to is big enough */

int main()
{
    char cur_line[MAX_LENGTH];    /* current input line */
    int cur_line_length;          /* current input line length */

    char out[MAX_LINES][MAX_LENGTH];    /* output lines */
    int out_lines_count = 0;            /* indexer for out[][] lines */

    while (out_lines_count < MAX_LINES && (cur_line_length = getline_custom(cur_line, MAX_LENGTH)) > 0)
        if (rm_tr_whitespaces(cur_line, cur_line_length) > 0) {
            copy(out[out_lines_count], cur_line);
            ++out_lines_count;
        }
    
    int i;
    for (i = 0; i < out_lines_count; ++i)
        printf("%s", out[i]);

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

int rm_tr_whitespaces(char s[], int line_length)
{
    int i = line_length - 1;

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
        --i;
        
    if (i != -1 && s[line_length - 1] == '\n') {
        ++i;
        s[i] = '\n';
    }

    ++i;
    s[i] = '\0';
    
    return i;
}

void copy(char to[], char from[])
{
   int i = 0;

   while ((to[i] = from[i]) != '\0')
       ++i;
}
