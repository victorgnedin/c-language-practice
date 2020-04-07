/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */

#include <stdio.h>
#define TAB_STOP_LENGTH 4   /* assume TAB_STOP_LENGTH > 0 */

int main() 
{
    int c, i, j;
    int blanks_count = 0;

    for (i = 0; (c = getchar()) != EOF; ++i) {

        if (i == TAB_STOP_LENGTH) {
            if (blanks_count != 0) {
                printf("\t");
                blanks_count = 0;
            }
            i = 0;
        }

        switch (c) {
            case ' ':
                ++blanks_count;
                break;

            case '\n':
                printf("\n");
                i = -1;
                break;

            default:
                if (blanks_count != 0) {
                    for (j = 0; j < blanks_count; ++j)
                        printf(" ");
                    blanks_count = 0;
                }
                printf("%c", c);
        }
    }

    return 0;
}
