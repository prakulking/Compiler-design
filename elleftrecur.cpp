#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char* nonterminal, char* production) {
    char alpha[10], beta[10];
    sscanf(production, "%[^|]|%s", alpha, beta);

    if (nonterminal[0] == alpha[0]) {
        printf("%s -> %s%s'\n", nonterminal, beta, nonterminal);
        printf("%s' -> %s%s'|epsilon\n", nonterminal, alpha + 1, nonterminal);
    } else {
        printf("%s -> %s%s'\n", nonterminal, alpha, nonterminal);
        printf("%s' -> epsilon\n", nonterminal);
    }
}

int main() {
    char nonterminal[10], production[20];
    printf("Enter the nonterminal: ");
    scanf("%s", nonterminal);
    printf("Enter the production (e.g., A -> Aa|b): ");
    scanf("%s", production);

    eliminateLeftRecursion(nonterminal, production);
    return 0;
}
