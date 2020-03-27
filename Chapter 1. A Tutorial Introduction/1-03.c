/* Excercise 1-3. Modify the temperature conversion program to print a heading above the table */

#include <stdio.h>

int main()
{
    /* Print Fahrenheit-Celsius table for fahrenheit = 0, 20, ..., 300; floating-point version */

    float fahrenheit, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("%10s%10s\n", "Fahrenheit", "Celsius");

    fahrenheit = lower;
    while (fahrenheit <= upper) {
        celsius = (5.0 / 9.0) * (fahrenheit - 32);
        printf("%10.0f%10.1f\n", fahrenheit, celsius);
        fahrenheit += step;
    }
    
    return 0;
}
