/* Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column */

#include <stdio.h>

#define MAX_IN_LEN 1024    /* max input line size including '\0'; assume all input lines <= MAX_IN_LEN */

#define TAB_STOP_LEN  4                                      /* tab stop size, assume TAB_STOP_LEN > 0 */
#define MAX_DETAB_LEN (MAX_IN_LEN - 1) * TAB_STOP_LEN + 1    /* max detab line size (if all input line chars are tabs) including '\0' */

#define MAX_SH_LEN    16                                               /* max shorter line size; including '\0' */
#define MAX_SH_AMOUNT (MAX_DETAB_LEN + MAX_SH_LEN - 1) / MAX_SH_LEN    /* max shorter lines amount */

int get_line(char line[], int max_in_len);    /* read a line (< max_in_len), return length including '\0' */
int detab_line(char line[], int line_len, int tab_stop_len);    /* replace tabs in the line with the proper number of blanks to space to the next tab stop, return length including '\0' */
int fold_line(char line[], int line_len, int max_sh_amount, int max_sh_len, char sh_lines[max_sh_amount][max_sh_len]);    /* fold line into two or more shorter lines (sh_lines), return shorter lines amount */
void copy(char to[], char from[]);    /* copy "from" into "to", assume "to" is big enough */

int main()
{
    char line[MAX_DETAB_LEN];                    /* input line */
    int line_len;                                /* input line length */
    char sh_lines[MAX_SH_AMOUNT][MAX_SH_LEN];    /* shorter lines */
    int sh_amount;                               /* shorter lines amount */

    while ((line_len = get_line(line, MAX_IN_LEN)) > 0) {

        line_len = detab_line(line, line_len, TAB_STOP_LEN);
        sh_amount = fold_line(line, line_len, MAX_SH_AMOUNT, MAX_SH_LEN, sh_lines);

        printf("Input line (%d columns) folds into %d shorter lines (up to %d columns):\n", line_len - 1, sh_amount, MAX_SH_LEN - 1);
        for (int i = 0; i < sh_amount; ++i)
            printf("%s", sh_lines[i]);
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i + 1;
}

int detab_line(char line[], int line_len, int tab_stop_len) {

    int i;                                              /* indexer for line[] */
    char new_line[(line_len - 1) * tab_stop_len + 1];   /* temporary array for detabbing */
    int j = 0;                                          /* indexer for new_line[] */
    int tab_pos = 0;                                    /* current tab position */

    for (i = 0; i < line_len - 1; ++i) {

        if (tab_pos == tab_stop_len)
            tab_pos = 0;

        switch (line[i]) {
            case '\t':
                for (int k = tab_pos; k < tab_stop_len; ++k)
                    new_line[j++] = ' ';
                tab_pos = 0;
                break;

            default:
                new_line[j++] = line[i];
                ++tab_pos;
        }
    }
    new_line[j] = '\0';
    copy(line, new_line);

    return j + 1;
}

int fold_line(char line[], int line_len, int max_sh_amount, int max_sh_len, char sh_lines[max_sh_amount][max_sh_len])
{
    int i = 0;                      /* indexer for sh_lines[i][] */
    int j;                          /* indexer for sh_lines[][j] */
    int sh_beg = 0;                 /* index of the first char of a shorter line inside line[] */
    int sh_end = max_sh_len - 3;    /* index of the last char of shorter line inside line[] */

    while (sh_end < line_len - 1) {

        /* tuning sh_end value */ 
        while (line[sh_end + 1] != ' ' && sh_end > sh_beg)
            --sh_end;
        while (line[sh_end] == ' ' && sh_end > sh_beg)
            --sh_end;
        if (sh_end <= sh_beg)
            sh_end = sh_beg + max_sh_len - 3;

        /* writing shorter line and setting new sh_beg value */
        for (j = 0; sh_beg <= sh_end; ++sh_beg) 
            sh_lines[i][j++] = line[sh_beg];
        sh_lines[i][j++] = '\n';
        sh_lines[i++][j++] = '\0';

        /* tuning sh_beg value */
        while (line[sh_beg] == ' ')
            ++sh_beg;
        
        /* setting new sh_end value */
        sh_end = sh_beg + max_sh_len - 3;
    }

    sh_end = line_len - 1;
    for (j = 0; sh_beg <= sh_end; ++sh_beg)
        sh_lines[i][j++] = line[sh_beg];
    
    return i + 1;
}

void copy(char to[], char from[])
{
   int i = 0;

   while ((to[i] = from[i]) != '\0')
       ++i;
}
