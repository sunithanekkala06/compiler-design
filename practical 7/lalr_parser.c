// Practical 7: LALR Parsing in C

#include <stdio.h>
#include <string.h>

#define SIZE 50

// Grammar: E -> E+T | T, T -> T*F | F, F -> (E) | id
// States and LALR parsing table (simplified)

int stateStack[SIZE];
char symStack[SIZE];
int top = -1;

void pushState(int s) { stateStack[++top] = s; }
void pushSym(char c) { symStack[top] = c; }
int popState() { return stateStack[top--]; }
int peekState() { return stateStack[top]; }

int main() {
    char input[SIZE];

    printf("========================================\n");
    printf("        LALR Parser (E->E+T|T)\n");
    printf("========================================\n");
    printf("Enter input (use i=id, end with $): ");
    scanf("%s", input);

    int i = 0;
    pushState(0);
    top = 0;

    printf("\n%-15s %-15s %-15s\n", "State Stack", "Input", "Action");
    printf("--------------------------------------------------\n");

    while (1) {
        int state = peekState();
        char a = input[i];

        printf("%-15d %-15s ", state, input + i);

        // LALR Table (simplified for E->E+T|T, T->F, F->id)
        if (state == 0 && a == 'i') {
            pushState(5); i++;
            printf("Shift 5\n");
        } else if (state == 5) {
            // Reduce F -> id
            popState();
            int s = peekState();
            printf("Reduce F -> id\n");
            if (s == 0) pushState(3);
            else if (s == 4) pushState(3);
            else if (s == 6) pushState(3);
        } else if (state == 3) {
            // Reduce T -> F
            popState();
            int s = peekState();
            printf("Reduce T -> F\n");
            if (s == 0) pushState(2);
            else if (s == 6) pushState(9);
            else pushState(2);
        } else if (state == 2 && a == '+') {
            pushState(6); i++;
            printf("Shift 6\n");
        } else if (state == 2 && a == '$') {
            // Reduce E -> T
            popState();
            printf("Reduce E -> T\n");
            pushState(1);
        } else if (state == 1 && a == '$') {
            printf("Accept!\n");
            printf("\n========================================\n");
            printf("String ACCEPTED by LALR Parser!\n");
            printf("========================================\n");
            break;
        } else if (state == 6 && a == 'i') {
            pushState(5); i++;
            printf("Shift 5\n");
        } else if (state == 9 && (a == '+' || a == '$')) {
            popState(); popState();
            printf("Reduce E -> E + T\n");
            pushState(1);
        } else if (state == 1 && a == '+') {
            pushState(6); i++;
            printf("Shift 6\n");
        } else {
            printf("Error!\n");
            break;
        }
    }
    return 0;
}