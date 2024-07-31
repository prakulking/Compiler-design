#include <stdio.h>
#include <string.h>

void eliminateLeftFactoring(char* nonterminal, char* production) {
    char common[10], remaining[10], rest[10];
    sscanf(production, "%[^|]", common);
    sscanf(production + strlen(common) + 1, "%s", remaining);
    
    int i = 0;
    while (common[i] == remaining[i]) {
        i++;
    }
    
    strncpy(rest, common, i);
    rest[i] = '\0';
    
    printf("%s -> %s%s'\n", nonterminal, rest, nonterminal);
    printf("%s' -> %s|%s\n", nonterminal, common + i, remaining + i);
}

int main() {
    char nonterminal[10], production[20];
    printf("Enter the nonterminal: ");
    scanf("%s", nonterminal);
    printf("Enter the production (e.g., A -> abc|abd): ");
    scanf("%s", production);

    eliminateLeftFactoring(nonterminal, production);
    return 0;
}
