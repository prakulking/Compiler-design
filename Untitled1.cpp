#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char nonTerminal;
    char productions[MAX][MAX];
    int prodCount;
} Grammar;

void eliminateLeftRecursion(Grammar* grammar, int count) {
    for (int i = 0; i < count; i++) {
        int hasLeftRecursion = 0;
        Grammar newGrammar;
        newGrammar.nonTerminal = grammar[i].nonTerminal;
        newGrammar.prodCount = 0;
        char newNonTerminal = grammar[i].nonTerminal + '\'';
        
        for (int j = 0; j < grammar[i].prodCount; j++) {
            if (grammar[i].productions[j][0] == grammar[i].nonTerminal) {
                hasLeftRecursion = 1;
                snprintf(newGrammar.productions[newGrammar.prodCount++], MAX, "%s%c", grammar[i].productions[j] + 1, newNonTerminal);
            }
        }

        if (hasLeftRecursion) {
            for (int j = 0; j < grammar[i].prodCount; j++) {
                if (grammar[i].productions[j][0] != grammar[i].nonTerminal) {
                    snprintf(grammar[i].productions[j] + strlen(grammar[i].productions[j]), MAX - strlen(grammar[i].productions[j]), "%c", newNonTerminal);
                }
            }
            snprintf(grammar[i].productions[grammar[i].prodCount++], MAX, "%c", '\0');

            for (int j = 0; j < newGrammar.prodCount; j++) {
                snprintf(newGrammar.productions[j] + strlen(newGrammar.productions[j]), MAX - strlen(newGrammar.productions[j]), "%c", newNonTerminal);
            }
            snprintf(newGrammar.productions[newGrammar.prodCount++], MAX, "%c", '\0');

            grammar[count++] = newGrammar;
        }
    }

    printf("The grammar after eliminating left recursion is:\n");
    for (int i = 0; i < count; i++) {
        printf("%c -> ", grammar[i].nonTerminal);
        for (int j = 0; j < grammar[i].prodCount; j++) {
            if (j > 0) printf(" | ");
            printf("%s", grammar[i].productions[j]);
        }
        printf("\n");
    }
}

int main() {
    Grammar grammar[MAX];
    int count;

    printf("Enter the number of non-terminals: ");
    scanf("%d", &count);
    getchar();

    for (int i = 0; i < count; i++) {
        printf("Enter the non-terminal: ");
        scanf("%c", &grammar[i].nonTerminal);
        getchar();
        printf("Enter the number of productions for %c: ", grammar[i].nonTerminal);
        scanf("%d", &grammar[i].prodCount);
        getchar();
        for (int j = 0; j < grammar[i].prodCount; j++) {
            printf("Enter production %d: ", j + 1);
            fgets(grammar[i].productions[j], MAX, stdin);
            grammar[i].productions[j][strcspn(grammar[i].productions[j], "\n")] = '\0';
        }
    }

    eliminateLeftRecursion(grammar, count);

    return 0;
}

























