/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text */

#include <stdio.h>
#define MAXLINE 10    /* maximum input line size */

int getline_custom(char s[], int lim);
void copy(char to[], char from[]);

/* print length and text of the longest input line */
int main()
{
    int len;                    /* current line length (<= MAXLINE - 1) */
    int comp_len = 0;           /* composite line length (> MAXLINE - 1) */
    int max = 0;                /* maximum length seen so far */
    char line[MAXLINE];         /* current input line */
    char comp_line[MAXLINE];    /* composite input line */
    char longest[MAXLINE];      /* longest line saved here */

    while ((len = getline_custom(line, MAXLINE)) > 0) {

        if (len == MAXLINE - 1 && line[MAXLINE - 2] != '\n') {
            if (comp_len == 0)
                copy(comp_line, line);
            comp_len = comp_len + len;
        }
        else if (comp_len == 0) {
            if (len > max) {
                max = len;
                copy(longest, line);
            }
        }
        else {
            if (comp_len + len > max) {
                max = comp_len + len;
                copy(longest, comp_line);
            }
            comp_len = 0;
        }
    }
    
    if (max > 0) {    /* there was a line */
        printf("The longest line has %d charactes:", max);
        if (max > MAXLINE)    /* line lengths was longer than a maximum input line size */
            printf("\b, printing first %d:", MAXLINE - 1);
        printf("\n%s\n", longest);
    }    

    return 0;
}

/* getline_custom: read a line into s, return length */
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

/* copy: compy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
   int i = 0;

   while ((to[i] = from[i]) != '\0')
       ++i;
}
