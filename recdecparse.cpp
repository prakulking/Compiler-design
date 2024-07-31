#include <stdio.h>
#include <stdlib.h>

char *input;
int i = 0;

void E();
void T();
void F();

void E() {
    T();
    while (input[i] == '+' || input[i] == '-') {
        i++;
        T();
    }
}

void T() {
    F();
    while (input[i] == '*' || input[i] == '/') {
        i++;
        F();
    }
}

void F() {
    if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') {
            i++;
        } else {
            printf("Error: Missing closing parenthesis\n");
            exit(1);
        }
    } else if (input[i] >= '0' && input[i] <= '9') {
        while (input[i] >= '0' && input[i] <= '9') {
            i++;
        }
    } else {
        printf("Error: Invalid character\n");
        exit(1);
    }
}

int main() {
    input = (char *)malloc(100 * sizeof(char));
    printf("Enter an expression: ");
    scanf("%s", input);

    E();

    if (input[i] == '\0')
        printf("The string is accepted.\n");
    else
        printf("The string is not accepted.\n");

    free(input);
    return 0;
}
