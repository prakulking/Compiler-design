#include <stdio.h>
#include <string.h>

void optimizeCode(char* code) {
    char optimizedCode[100] = "";
    char* token = strtok(code, "\n");

    while (token != NULL) {
        if (strstr(optimizedCode, token) == NULL) {
            strcat(optimizedCode, token);
            strcat(optimizedCode, "\n");
        }
        token = strtok(NULL, "\n");
    }

    printf("Optimized Code:\n%s", optimizedCode);
}

int main() {
    char code[1000] = "t1 = a + b\nt2 = a + b\nt3 = t1 * c\n";

    printf("Original Code:\n%s\n", code);
    optimizeCode(code);

    return 0;
}
