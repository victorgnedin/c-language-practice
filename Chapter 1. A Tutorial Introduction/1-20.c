/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter? */

#include <stdio.h>
#define TAB_STOP_LENGTH 4   /* assume TAB_STOP_LENGTH > 0 */

int main() 
{
    int c, i, j;

    for (i = 0; (c = getchar()) != EOF; ++i) {

        if (i == TAB_STOP_LENGTH)
            i = 0;

        switch (c) {
            case '\t':
                for (j = i; j < TAB_STOP_LENGTH; ++j)
                    printf(" ");
                i = -1;
                break;

            case '\n':
                printf("\n");
                i = -1;
                break;

            default:
                printf("%c", c);
        }
    }

    return 0;
}
