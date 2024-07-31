#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Grammar: S -> aSb | epsilon

int i = 0;
char input[100];

void S() {
    if (input[i] == 'a') {
        i++;
        S();
        if (input[i] == 'b') {
            i++;
        }
    }
}

int main() {
    printf("Enter a string: ");
    gets(input);

    S();

    if (input[i] == '\0')
        printf("The string is accepted.\n");
    else
        printf("The string is not accepted.\n");

    return 0;
}
