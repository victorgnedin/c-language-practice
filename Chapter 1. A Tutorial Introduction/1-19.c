/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to write a program that reverses its input line at a time */
/* DISCLAIMER: This solution assumes that input lines are less than MAX_LENGTH characters, because the task does not specify if and how I should hadle longer lines */

#include <stdio.h>

#define MAX_LENGTH 1000    /* maximum input/output line size */

int getline_custom(char s[], int lim);      /* read a line into s, return length */
void reverse(char s[], int line_length);    /* reverse characters in string s */

int main()
{
    char cur_line[MAX_LENGTH];    /* current input line */
    int cur_line_length;          /* current input line length */

    while ((cur_line_length = getline_custom(cur_line, MAX_LENGTH)) > 0) {

        if (cur_line[cur_line_length - 1] == '\n')    /* In a sake of nice output let's reverse everything except the last '\n' */
            --cur_line_length;

        reverse(cur_line, cur_line_length);
        printf("%s", cur_line);
    }

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

void reverse(char s[], int line_length)
{
    int c, i, last_char_index = line_length - 1;

    for (i = 0; i < (line_length / 2); ++i) {
        c = s[i];
        s[i] = s[last_char_index - i];
        s[last_char_index - i] = c;
    }
}
