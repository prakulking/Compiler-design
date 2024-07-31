#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char op[10];
    char arg1[10];
    char arg2[10];
    char result[10];
} Instruction;

Instruction instructions[100];
int instructionCount = 0;

void addInstruction(char* op, char* arg1, char* arg2, char* result) {
    strcpy(instructions[instructionCount].op, op);
    strcpy(instructions[instructionCount].arg1, arg1);
    strcpy(instructions[instructionCount].arg2, arg2);
    strcpy(instructions[instructionCount].result, result);
    instructionCount++;
}

void generateAssembly() {
    for (int i = 0; i < instructionCount; i++) {
        if (strcmp(instructions[i].op, "+") == 0) {
            printf("MOV R0, %s\n", instructions[i].arg1);
            printf("ADD R0, %s\n", instructions[i].arg2);
            printf("MOV %s, R0\n", instructions[i].result);
        } else if (strcmp(instructions[i].op, "-") == 0) {
            printf("MOV R0, %s\n", instructions[i].arg1);
            printf("SUB R0, %s\n", instructions[i].arg2);
            printf("MOV %s, R0\n", instructions[i].result);
        } else if (strcmp(instructions[i].op, "*") == 0) {
            printf("MOV R0, %s\n", instructions[i].arg1);
            printf("MUL R0, %s\n", instructions[i].arg2);
            printf("MOV %s, R0\n", instructions[i].result);
        } else if (strcmp(instructions[i].op, "/") == 0) {
            printf("MOV R0, %s\n", instructions[i].arg1);
            printf("DIV R0, %s\n", instructions[i].arg2);
            printf("MOV %s, R0\n", instructions[i].result);
        }
    }
}

int main() {
    addInstruction("+", "a", "b", "t1");
    addInstruction("*", "t1", "c", "t2");
    addInstruction("-", "t2", "d", "t3");

    printf("Intermediate Code:\n");
    for (int i = 0; i < instructionCount; i++) {
        printf("%s = %s %s %s\n", instructions[i].result, instructions[i].arg1, instructions[i].op, instructions[i].arg2);
    }

    printf("\nAssembly Code:\n");
    generateAssembly();

    return 0;
}
