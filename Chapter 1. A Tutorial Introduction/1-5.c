/* Excercise 1-5. Modify the temperature conversion program to print the table in reversed order, that is, from 300 degrees to 0 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main()
{
    int fahrenheit;

    for (fahrenheit = UPPER; fahrenheit >= LOWER; fahrenheit -= STEP)
        printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));

    return 0;
}
