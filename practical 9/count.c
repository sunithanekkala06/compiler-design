// Practical 9a: Count Characters, Lines and Words in C

#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("========================================\n");
    printf("  Count Characters, Words and Lines\n");
    printf("========================================\n");
    printf("Enter text (type END on new line to stop):\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "END\n") == 0) break;

        int len = strlen(input);
        lines++;

        for (int i = 0; i < len; i++) {
            chars++;
            if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
                if (inWord) { words++; inWord = 0; }
            } else {
                inWord = 1;
            }
        }
    }
    if (inWord) words++;

    printf("\n--- Result ---\n");
    printf("Characters : %d\n", chars);
    printf("Words      : %d\n", words);
    printf("Lines      : %d\n", lines);
    printf("========================================\n");
    return 0;
}