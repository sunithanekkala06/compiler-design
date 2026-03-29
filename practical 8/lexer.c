// Practical 8: Study of Lexical Analyzer Generator (LEX) and Flex
// Simulated Lexical Analyzer in C

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int keywords = 0, identifiers = 0, numbers = 0, operators = 0, unknown = 0;

// Check if word is a keyword
int isKeyword(char *word) {
    char *kw[] = {"int", "float", "char", "double", "if", "else",
                  "while", "for", "return", "void", "main", "include"};
    int n = 12;
    for (int i = 0; i < n; i++)
        if (strcmp(word, kw[i]) == 0)
            return 1;
    return 0;
}

void analyze(char *input) {
    int i = 0;
    int len = strlen(input);

    while (i < len) {
        // Skip whitespace
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Identifier or Keyword
        if (isalpha(input[i]) || input[i] == '_') {
            char word[50] = "";
            int j = 0;
            while (i < len && (isalnum(input[i]) || input[i] == '_'))
                word[j++] = input[i++];
            word[j] = '\0';

            if (isKeyword(word)) {
                printf("KEYWORD     : %s\n", word);
                keywords++;
            } else {
                printf("IDENTIFIER  : %s\n", word);
                identifiers++;
            }
        }

        // Number
        else if (isdigit(input[i])) {
            char num[50] = "";
            int j = 0;
            while (i < len && (isdigit(input[i]) || input[i] == '.'))
                num[j++] = input[i++];
            num[j] = '\0';
            printf("NUMBER      : %s\n", num);
            numbers++;
        }

        // Operator
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' ||
                 input[i] == '/' || input[i] == '=' || input[i] == '<' ||
                 input[i] == '>' || input[i] == '!' || input[i] == '%') {
            printf("OPERATOR    : %c\n", input[i]);
            operators++;
            i++;
        }

        // Unknown / Symbol
        else {
            printf("SYMBOL      : %c\n", input[i]);
            unknown++;
            i++;
        }
    }
}

int main() {
    char input[500];

    printf("========================================\n");
    printf("  Lexical Analyzer Generator (LEX)\n");
    printf("========================================\n");
    printf("Enter a C expression or statement:\n");
    printf("> ");
    fgets(input, sizeof(input), stdin);

    // Remove newline
    input[strcspn(input, "\n")] = '\0';

    printf("\n--- Tokens ---\n");
    analyze(input);

    printf("\n--- Summary ---\n");
    printf("Keywords    : %d\n", keywords);
    printf("Identifiers : %d\n", identifiers);
    printf("Numbers     : %d\n", numbers);
    printf("Operators   : %d\n", operators);
    printf("Symbols     : %d\n", unknown);
    printf("========================================\n");

    return 0;
}
