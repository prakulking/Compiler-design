#include <stdio.h>
#include <ctype.h>

void count(char* filename) {
    FILE *file;
    char c;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file \n");
        return;
    }

    while ((c = fgetc(file)) != EOF) {
        characters++;

        if (c == '\n') {
            lines++;
        }

        if (isspace(c)) {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            words++;
        }
    }

    fclose(file);

    printf("Characters: %d\n", characters);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    count(filename);
    return 0;
}
