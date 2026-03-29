// Practical 9b: Count Vowels and Consonants in C

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[1000];
    int vowels = 0, consonants = 0;

    printf("========================================\n");
    printf("     Count Vowels and Consonants\n");
    printf("========================================\n");
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        char c = tolower(input[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels++;
        } else if (c >= 'a' && c <= 'z') {
            consonants++;
        }
    }

    printf("\n--- Result ---\n");
    printf("Vowels     : %d\n", vowels);
    printf("Consonants : %d\n", consonants);
    printf("========================================\n");
    return 0;
}