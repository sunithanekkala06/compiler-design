// Practical 3: Program to check validation of User Name and Password in C

#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3

int main() {
    char valid_username[] = "admin";
    char valid_password[] = "pass123";

    char username[50];
    char password[50];
    int attempts = 0;
    int success = 0;

    printf("========================================\n");
    printf("     User Name and Password Validation  \n");
    printf("========================================\n");

    while (attempts < MAX_ATTEMPTS) {
        printf("\nAttempt %d of %d\n", attempts + 1, MAX_ATTEMPTS);
        printf("Enter Username: ");
        scanf("%s", username);
        printf("Enter Password: ");
        scanf("%s", password);

        if (strcmp(username, valid_username) == 0 && strcmp(password, valid_password) == 0) {
            success = 1;
            break;
        } else {
            printf("Invalid Username or Password! Try again.\n");
            attempts++;
        }
    }

    printf("\n========================================\n");
    if (success) {
        printf("Access Granted! Welcome, %s!\n", username);
    } else {
        printf("Access Denied! Maximum attempts reached.\n");
    }
    printf("========================================\n");

    return 0;
}