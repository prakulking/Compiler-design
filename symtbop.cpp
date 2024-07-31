#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

typedef struct {
    char identifier[30];
    char type[10];
    int lineNo;
} SymbolTableEntry;

SymbolTableEntry symbolTable[SIZE];
int count = 0;

void insert(char *id, char *type, int line) {
    strcpy(symbolTable[count].identifier, id);
    strcpy(symbolTable[count].type, type);
    symbolTable[count].lineNo = line;
    count++;
}

void display() {
    printf("\nSymbol Table:\n");
    printf("Identifier\tType\tLine No\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t%d\n", symbolTable[i].identifier, symbolTable[i].type, symbolTable[i].lineNo);
    }
}

int main() {
    insert("a", "int", 1);
    insert("b", "float", 2);
    insert("sum", "int", 3);
    display();
    return 0;
}
