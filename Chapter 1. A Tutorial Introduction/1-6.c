/* Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1 */

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
        printf("getchar() != EOF (true): %d\n", getchar() != EOF); 

    /* Ctrl-D to pass eof to the terminal's input and break out of while loop */

    printf("getchar() == EOF (false): %d\n", getchar() != EOF);

    return 0;
}
