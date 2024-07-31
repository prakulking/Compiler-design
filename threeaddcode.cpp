#include <stdio.h>
#include <string.h>

void generateThreeAddressCode(char* expression) {
    char result[100];
    int tempCount = 1;

    printf("Three Address Code:\n");
    for (int i = 0; i < strlen(expression); i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            printf("t%d = %c %c %c\n", tempCount, expression[i - 1], expression[i], expression[i + 1]);
            expression[i - 1] = 't';
            expression[i] = tempCount + '0';
            tempCount++;
        }
    }
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    scanf("%s", expression);

    generateThreeAddressCode(expression);
    return 0;
}
