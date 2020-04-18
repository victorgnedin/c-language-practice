/* Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest */

#include <stdio.h>

#define MAX_IN_LEN     1024    /* max input line size including '\0'; assume all input lines <= MAX_IN_LEN */
#define MAX_OUT_AMOUNT 128     /* max output lines amount */

int get_line(char line[], int max_in_len);    /* read a line (< max_in_len), return length including '\0' */
int del_substr(char str[], int str_len, int del_from, int del_to);    /* delete substring [str[del_from], str[del_to]] from str[], return length including '\0'; str_len expected to include '\0'; assume del_from < del_to < str_len */
void copy(char to[], char from[]);    /* copy "from" into "to", assume "to" is big enough */

int main() 
{
    char line[MAX_IN_LEN];    /* input line */
    int line_len;             /* input line length */

    char lines[MAX_OUT_AMOUNT][MAX_IN_LEN];    /* output lines */
    int lines_amount = 0;

    int comment = -1;    /* first char index of a comment inside line[], otherwise -1 */
    int literal = -1;    /* first char index of a string or character literal inside line[], otherwise -1 */

    while ((line_len = get_line(line, MAX_IN_LEN)) > 1) {
        int i = 0;
        while (i < line_len) {
            if (literal == -1) {
                if (line[i] == '\'' || line[i] == '\"') {
                    literal = i;
                } else if (line[i] == '/') {
                    if (comment == -1 && i + 1 < line_len && line[i + 1] == '*') {
                        comment = i;
                    } else if (comment != -1 && line[i - 1] == '*') {
                        line_len = del_substr(line, line_len, comment, i);
                        i = comment - 1;
                        comment = -1;
                    }
                }
            } else {
                if (line[i] == line[literal] && line[i - 1] != '\\')
                    literal = -1;
            }
            ++i;
        }
        if (comment != -1) {
            line[comment] = '\0';
            comment = 0;
        }
        if (literal != -1)
            literal = 0;
        copy(lines[lines_amount], line);
        ++lines_amount;
    }

    /* printing result */
    for (int k = 0; k < lines_amount; ++k)
        printf("%s", lines[k]);

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i + 1;
}

int del_substr(char str[], int str_len, int del_from, int del_to)
{
    while (++del_to < str_len)
        str[del_from++] = str[del_to];

    return del_from;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}
