/* Exercise 1-24. Write a program to check a C program for rudimentory syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments */
/* Solution checks the balance of (), [], {}, "", '' and comments in a C program */

#include <stdio.h>
#include <stdbool.h>

#define MAX_IN_LENGTH 1024    /* max input line size including '\0'; assume all input lines <= MAX_IN_LEN */

int get_line(char line[], int max_length);    /* read a line (< max_length) from input, return length including '\0' */

enum check {parentheses, brackets, braces, d_quotes, quotes, comments};
char* check_string_map[] = {"parentheses", "brackets", "braces", "double quotes", "quotes", "comments"};

int main() 
{
    char line[MAX_IN_LENGTH];    /* input line */
    int line_length;             /* input line length */

    int balance[6] = {0, 0, 0, 0, 0, 0};    /* open (paranthesis, bracket, ...) gives +1 to the balance[parantheses, brackets, ...], close -1; Parantheses, brackets, ... balanced only when balance[parantheses, brackets, ...] == 0 */

    bool comment = false;        /* states whether we're inside the comment or not */
    bool literal = false;        /* states whether we're inside the literal or not */
    char literal_type = '\0';    /* used when literal == true, can be either '\"' or '\'' */

    while ((line_length = get_line(line, MAX_IN_LENGTH)) > 1) {

        int i = 0;
        while (i < line_length) {
            if (!comment && !literal) {
                switch (line[i]) {
                    case '(':
                    case ')':
                        (line[i] == '(') ? ++balance[parentheses] : --balance[parentheses];
                        break;
                    case '[':
                    case ']':
                        (line[i] == '[') ? ++balance[brackets] : --balance[brackets];
                        break;
                    case '{':
                    case '}':
                        (line[i] == '{') ? ++balance[braces] : --balance[braces];
                        break;
                    case '\"':
                    case '\'':
                        (line[i] == '\"') ? ++balance[d_quotes] : ++balance[quotes];
                        literal = true;
                        literal_type = (line[i] == '\"') ? '\"' : '\'';
                        break;
                    case '/':
                        if (i + 1 < line_length && line[i + 1] == '*') {
                            ++balance[comments];
                            comment = true;
                        }
                        break;
                }  
            } else if (literal) {
                if (line[i] == '\\') {
                    /* Here could be an espace sequence validation */
                    ++i;
                } else if (line[i] == literal_type) {
                    (literal_type == '\"') ? --balance[d_quotes] : --balance[quotes];
                    literal = false;
                }
            } else if (comment && line[i] == '/' && line[i - 1] == '*') {
                --balance[comments];
                comment = false;
            }

            ++i;
        }
    }

    /* printing result */
    if (balance[parentheses] == 0 && balance[brackets] == 0 && balance[braces] == 0 && balance[d_quotes] == 0 && balance[quotes] == 0 && balance[comments] == 0) {
        printf("Congrats, everything is balanced\n");
    } else {
        printf("C program got unbalanced ");
        for (int j = 0; j < 6; ++j)
            if (balance[j] != 0)
                printf("%s, ", check_string_map[j]);
        printf("\b\b.");
    }

    return 0;
}

int get_line(char line[], int max_length)
{
    int c, i;

    for (i = 0; i < max_length - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i + 1;
}
