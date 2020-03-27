/* Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion */ 

#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP  20

float fahrenheit_to_celsius(float fahrenheit);

int main()
{
    /* Print Fahrenheit-Celsius table for fahrenheit = 0, 20, ..., 300; floating-point version */

    float fahrenheit;
    
    printf("%10s%10s\n", "Fahrenheit", "Celsius");

    fahrenheit = LOWER;
    while (fahrenheit <= UPPER) {
        printf("%10.0f%10.1f\n", fahrenheit, fahrenheit_to_celsius(fahrenheit));
        fahrenheit = fahrenheit + STEP;
    }
    
    return 0;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    return (5.0 / 9.0) * (fahrenheit - 32);
}
