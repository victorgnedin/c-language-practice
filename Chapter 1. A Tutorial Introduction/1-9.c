/* Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank */

#include <stdio.h>

#define TRUE  1
#define FALSE 0

int main()
{
    char c;
    char isExtraBlank = FALSE;    /* This char is used as boolean */
    
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (isExtraBlank == FALSE) {
                putchar(c);
                isExtraBlank = TRUE;
            }
        } else {
            putchar(c);
            isExtraBlank = FALSE;
        } 
    }

    return 0;
}
