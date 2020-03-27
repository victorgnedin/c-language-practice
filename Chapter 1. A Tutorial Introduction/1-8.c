/* Exercise 1-8. Write a program to count blanks, tabs, and newlines */

#include <stdio.h>

int main()
{
    char c;
    int count = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++count;
        }  
    }

    printf("Number of blanks, tabs and newlines: %d\n", count);

    return 0;
}
