#include <stdio.h>
#include <stdlib.h>

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
    }
    return 0;
}

int evaluate(char* tokens) {
    int i;
    
    int values[100];
    int valuesIndex = -1;

    char ops[100];
    int opsIndex = -1;

    for (i = 0; i < strlen(tokens); i++) {
        if (tokens[i] == ' ')
            continue;

        else if (tokens[i] == '(') {
            ops[++opsIndex] = tokens[i];
        }
        else if (isdigit(tokens[i])) {
            int val = 0;

            while (i < strlen(tokens) && isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }
            values[++valuesIndex] = val;
            i--;
        }
        else if (tokens[i] == ')') {
            while (opsIndex != -1 && ops[opsIndex] != '(') {
                int val2 = values[valuesIndex--];
                int val1 = values[valuesIndex--];
                char op = ops[opsIndex--];

                values[++valuesIndex] = applyOp(val1, val2, op);
            }
            opsIndex--;
        }
        else {
            while (opsIndex != -1 && precedence(ops[opsIndex]) >= precedence(tokens[i])) {
                int val2 = values[valuesIndex--];
                int val1 = values[valuesIndex--];
                char op = ops[opsIndex--];

                values[++valuesIndex] = applyOp(val1, val2, op);
            }
            ops[++opsIndex] = tokens[i];
        }
    }

    while (opsIndex != -1) {
        int val2 = values[valuesIndex--];
        int val1 = values[valuesIndex--];
        char op = ops[opsIndex--];

        values[++valuesIndex] = applyOp(val1, val2, op);
    }
    
    return values[valuesIndex];
}

int main() {
    char expression[100];
    printf("Enter an expression: ");
    gets(expression);

    printf("Result: %d\n", evaluate(expression));
    return 0;
}
