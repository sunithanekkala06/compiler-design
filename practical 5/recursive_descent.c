// Practical 5: Recursive Descent Parsing in C

#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

void E();
void T();
void F();

void match(char c) {
    if (input[pos] == c) {
        printf("Matched: %c\n", c);
        pos++;
    } else {
        printf("Error! Expected %c but found %c\n", c, input[pos]);
    }
}

// E -> T + E | T
void E() {
    printf("E -> T\n");
    T();
    if (input[pos] == '+') {
        match('+');
        printf("E -> + E\n");
        E();
    }
}

// T -> F * T | F
void T() {
    printf("T -> F\n");
    F();
    if (input[pos] == '*') {
        match('*');
        printf("T -> * T\n");
        T();
    }
}

// F -> (E) | i
void F() {
    if (input[pos] == 'i') {
        match('i');
        printf("F -> id\n");
    } else if (input[pos] == '(') {
        match('(');
        E();
        match(')');
        printf("F -> (E)\n");
    } else {
        printf("Error!\n");
    }
}

int main() {
    printf("========================================\n");
    printf("     Recursive Descent Parser\n");
    printf("========================================\n");
    printf("Enter input string (use i for id, end with $): ");
    scanf("%s", input);

    E();

    if (input[pos] == '$') {
        printf("\n========================================\n");
        printf("String ACCEPTED!\n");
        printf("========================================\n");
    } else {
        printf("\nString REJECTED!\n");
    }
    return 0;
}