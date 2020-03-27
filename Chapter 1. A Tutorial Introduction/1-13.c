/* Exercise 1-13. Write a program to print a histogram of the lenghts of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging */

#include <stdio.h>
#define ARRAY_LENGTH 15

void print_vertical_histogram(int input[], char symbol);

int main()
{
    char c;
    int i, wordsLength[ARRAY_LENGTH], count = 0;

    for (i = 0; i < ARRAY_LENGTH; ++i)
        wordsLength[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++wordsLength[count];         
            count = 0;
        } 
        else 
            ++count;
    }
    /* When getchar() == EOF while-loop stops without adding the last word to the array */
    ++wordsLength[count]; 

    print_vertical_histogram(wordsLength, '#');

    return 0;
}

void print_vertical_histogram(int input[], char symbol)
{
    int i, i1, maxValue = 0;
    
    /* Looking for max value in input[] */

    for (i = 1; i < ARRAY_LENGTH; ++i) {
        if (input[i] > maxValue)
            maxValue = input[i];
    }

    /* Printing histogram top to bottom */

    printf("\n");
    for (i = maxValue; i > 0; --i ) {
        printf("%2d |", i);
        for (i1 = 1; i1 < ARRAY_LENGTH; ++i1) {
            if (input[i1] >= i)
                printf("%2c ", symbol); 
            else
                printf("%2c ", ' ');
        }
        printf("\n");
    }
    
    /* Printing separator line */
    
    printf("%3c|", ' ');
    for (i = 1; i < ARRAY_LENGTH; ++i)
        printf("---");
    printf("\n");

    /* Printing X-axis values */

    printf("%4c", ' ');
    for (i = 1; i < ARRAY_LENGTH; ++i)
        printf("%2d ", i);
}
