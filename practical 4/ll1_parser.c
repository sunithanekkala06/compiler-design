// Practical 4: Predictive Parsing LL(1) in C

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 128

char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int main() {
    // LL(1) Parsing Table for grammar:
    // E  -> TE'
    // E' -> +TE' | ε
    // T  -> FT'
    // T' -> *FT' | ε
    // F  -> (E) | id

    char input[SIZE];
    int i = 0;

    printf("========================================\n");
    printf("     LL(1) Predictive Parser\n");
    printf("========================================\n");
    printf("Grammar:\n");
    printf("  E  -> T E'\n");
    printf("  E' -> + T E' | epsilon\n");
    printf("  T  -> F T'\n");
    printf("  T' -> * F T' | epsilon\n");
    printf("  F  -> ( E ) | id\n");
    printf("========================================\n");
    printf("Enter input string (use 'i' for id, end with $): ");
    scanf("%s", input);

    int len = strlen(input);

    // Initialize stack
    push('$');
    push('E');

    printf("\n%-20s %-20s %-10s\n", "Stack", "Input", "Action");
    printf("--------------------------------------------------\n");

    while (top >= 0) {
        char X = peek();
        char a = input[i];

        // Print stack
        printf("%-20.*s ", top + 1, stack);
        // Print remaining input
        printf("%-20s ", input + i);

        if (X == '$' && a == '$') {
            printf("Accept\n");
            printf("\n========================================\n");
            printf("String ACCEPTED by LL(1) Parser!\n");
            printf("========================================\n");
            break;
        } else if (X == a) {
            pop();
            i++;
            printf("Match: %c\n", a);
        } else if (X == 'E') {
            pop();
            push('\''); push('E'); push('T');
            printf("E -> T E'\n");
        } else if (X == '\'') {  // E'
            if (a == '+') {
                pop();
                push('\''); push('E'); push('T'); push('+');
                printf("E' -> + T E'\n");
            } else {
                pop();
                printf("E' -> epsilon\n");
            }
        } else if (X == 'T') {
            pop();
            push('`'); push('F');
            printf("T -> F T'\n");
        } else if (X == '`') {  // T'
            if (a == '*') {
                pop();
                push('`'); push('T'); push('F'); push('*');
                printf("T' -> * F T'\n");
            } else {
                pop();
                printf("T' -> epsilon\n");
            }
        } else if (X == 'F') {
            if (a == 'i') {
                pop();
                push('i');
                printf("F -> id\n");
            } else if (a == '(') {
                pop();
                push(')'); push('E'); push('(');
                printf("F -> ( E )\n");
            } else {
                printf("Error!\n");
                break;
            }
        } else {
            printf("Error! No rule for %c with input %c\n", X, a);
            break;
        }
    }

    return 0;
}