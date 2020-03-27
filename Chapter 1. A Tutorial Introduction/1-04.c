/* Excercise 1-4. Write a program to print the corresponding Celsius to Fahrenheit table */

#include <stdio.h>

int main()
{
    /* Print Celsius-Fahrenheit table for celsius = -20, -10, ..., 150; floating-point version */

    float fahrenheit, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 150;
    step = 10;

    printf("%7s%12s\n", "Celsius", "Fahrenheit");

    celsius = lower;
    while (celsius <= upper) {
        fahrenheit = (9.0 / 5.0) * celsius + 32;
        printf("%7.0f%12.1f\n", celsius, fahrenheit);
        celsius = celsius + step;
    }

    return 0;
}
