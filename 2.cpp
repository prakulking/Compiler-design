#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    char nonTerminal;
    char productions[MAX][MAX];
    int prodCount;
} Grammar;

void eliminateLeftFactoring(Grammar* grammar, int count) {
    for (int i = 0; i < count; i++) {
        int prefixLength = 0;
        char commonPrefix[MAX] = {0};

        for (int j = 0; j < grammar[i].prodCount - 1; j++) {
            for (int k = j + 1; k < grammar[i].prodCount; k++) {
                int length = 0;
                while (grammar[i].productions[j][length] == grammar[i].productions[k][length] && 
                       grammar[i].productions[j][length] != '\0') {
                    length++;
                }
                if (length > prefixLength) {
                    prefixLength = length;
                    strncpy(commonPrefix, grammar[i].productions[j], prefixLength);
                    commonPrefix[prefixLength] = '\0';
                }
            }
        }

        if (prefixLength > 0) {
            Grammar newGrammar;
            newGrammar.nonTerminal = grammar[i].nonTerminal + '\'';
            newGrammar.prodCount = 0;

            for (int j = 0; j < grammar[i].prodCount; j++) {
                if (strncmp(grammar[i].productions[j], commonPrefix, prefixLength) == 0) {
                    snprintf(newGrammar.productions[newGrammar.prodCount++], MAX, "%s", grammar[i].productions[j] + prefixLength);
                } else {
                    snprintf(grammar[i].productions[j] + prefixLength, MAX - prefixLength, "%c", newGrammar.nonTerminal);
                }
            }
            snprintf(grammar[i].productions[0], MAX, "%s%c", commonPrefix, newGrammar.nonTerminal);
            grammar[i].prodCount = 1;

            grammar[count++] = newGrammar;
        }
    }

    printf("The grammar after eliminating left factoring is:\n");
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

    eliminateLeftFactoring(grammar, count);

    return 0;
}

