// Practical 6: Operator Precedence Parsing in C

#include <stdio.h>
#include <string.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

// Operator precedence table
// Rows: stack top, Columns: input
// Operators: + - * / ( ) $ i
// < means shift, > means reduce, = means match, ' ' means error

char ops[] = {'+', '-', '*', '/', '(', ')', '$', 'i'};
int numOps = 8;

char table[8][8] = {
    // +    -    *    /    (    )    $    i
    {'>', '>', '<', '<', '<', '>', '>', '<'},  // +
    {'>', '>', '<', '<', '<', '>', '>', '<'},  // -
    {'>', '>', '>', '>', '<', '>', '>', '<'},  // *
    {'>', '>', '>', '>', '<', '>', '>', '<'},  // /
    {'<', '<', '<', '<', '<', '=', ' ', '<'}, // (
    {'>', '>', '>', '>', ' ', '>', '>', ' '},  // )
    {'<', '<', '<', '<', '<', ' ', ' ', '<'}, // $
    {'>', '>', '>', '>', ' ', '>', '>', ' '}   // i
};

int getIndex(char c) {
    for (int i = 0; i < numOps; i++)
        if (ops[i] == c) return i;
    return -1;
}

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

int main() {
    char input[SIZE];
    printf("========================================\n");
    printf("   Operator Precedence Parser\n");
    printf("========================================\n");
    printf("Enter expression (end with $): ");
    scanf("%s", input);

    push('$');
    int i = 0;

    printf("\n%-20s %-20s %-10s\n", "Stack", "Input", "Action");
    printf("--------------------------------------------------\n");

    while (1) {
        char s = peek();
        char a = input[i];

        printf("%-20.*s %-20s ", top + 1, stack, input + i);

        int si = getIndex(s);
        int ai = getIndex(a);

        if (si == -1 || ai == -1) {
            printf("Error!\n");
            break;
        }

        char rel = table[si][ai];

        if (rel == '<' || rel == '=') {
            push(a);
            i++;
            printf("Shift %c\n", a);
        } else if (rel == '>') {
            char popped = pop();
            printf("Reduce: %c\n", popped);
        } else {
            if (s == '$' && a == '$') {
                printf("Accept!\n");
                printf("\n========================================\n");
                printf("String ACCEPTED!\n");
                printf("========================================\n");
            } else {
                printf("Error!\n");
            }
            break;
        }
    }
    return 0;
}