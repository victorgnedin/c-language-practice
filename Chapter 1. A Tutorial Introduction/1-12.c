/* Exercise 1-12. Write a program that prints its input one word per line */
/* I cleaned extra blanks, tabs and newlines as well, so there are only 'word + newline' pairs in output */

#include <stdio.h>

#define TRUE  1
#define FALSE 0

int main()
{
    char c;
    char isExtraWhitespace = TRUE;  /* This char is used as boolean */
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (isExtraWhitespace == FALSE) {
                putchar('\n');
                isExtraWhitespace = TRUE;
            }
        } else {
            putchar(c);
            isExtraWhitespace = FALSE;
        } 
    }

    return 0;
}
