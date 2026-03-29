// Practical 10a: Print all numbers from input in C

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char input[1000];

    printf("========================================\n");
    printf("      Print All Numbers from Input\n");
    printf("========================================\n");
    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    int i = 0, len = strlen(input);
    printf("\n--- Numbers Found ---\n");

    while (i < len) {
        if (isdigit(input[i])) {
            char num[50] = "";
            int j = 0;
            while (i < len && isdigit(input[i]))
                num[j++] = input[i++];
            num[j] = '\0';
            printf("Number: %s\n", num);
        } else {
            i++;
        }
    }
    printf("========================================\n");
    return 0;
}