/* Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input */
/* It's not completely clear from the task, frequencies of which characters should I print. Let them be all printable ASCII charactes (32–126). That is too many characters to show with histogtam with bars vertical (going to lack width), so I'll use histogram with bars horizontal instead */

#include <stdio.h>
#define ARRAY_LENGTH 95    /* There are 95 printable characters in ASCII (32-126) */ 

void print_horizontal_histogram(int input[], char symbol);

int main()
{
    int i, c, charFreq[ARRAY_LENGTH];

    for (i = 0; i < ARRAY_LENGTH; ++i)
        charFreq[i] = 0;

    /* ' ' is a first printable character in ASCII, '~' is the last */
    while ((c = getchar()) != EOF) {
        if (c >= ' ' && c <= '~')
            ++charFreq[c - ' '];
    }
    
    print_horizontal_histogram(charFreq, '#');

    return 0;
}

void print_horizontal_histogram(int input[], char symbol)
{
    int i, i1;

    for (i = 0; i < ARRAY_LENGTH; ++i) {
        printf("%c |", i + ' ');
        for (i1 = 0; i1 < input[i]; ++i1)
            printf("%c", symbol);
        printf("\n");
    }
}
