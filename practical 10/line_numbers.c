// Practical 10c: Add line numbers to output in C

#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    int lineNum = 1;

    printf("========================================\n");
    printf("       Add Line Numbers to Output\n");
    printf("========================================\n");
    printf("Enter text (type END to stop):\n");

    printf("\n--- Output with Line Numbers ---\n");

    while (1) {
        fgets(input, sizeof(input), stdin);
        if (strcmp(input, "END\n") == 0) break;
        printf("%d: %s", lineNum++, input);
    }

    printf("========================================\n");
    return 0;
}