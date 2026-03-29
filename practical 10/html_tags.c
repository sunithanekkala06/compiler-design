// Practical 10b: Print all HTML tags from input in C

#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    char tag[100];

    printf("========================================\n");
    printf("       Print All HTML Tags\n");
    printf("========================================\n");
    printf("Enter HTML string: ");
    fgets(input, sizeof(input), stdin);

    int i = 0, len = strlen(input);
    printf("\n--- HTML Tags Found ---\n");

    while (i < len) {
        if (input[i] == '<') {
            int j = 0;
            tag[j++] = input[i++];
            while (i < len && input[i] != '>') {
                tag[j++] = input[i++];
            }
            if (input[i] == '>') {
                tag[j++] = input[i++];
            }
            tag[j] = '\0';
            printf("Tag: %s\n", tag);
        } else {
            i++;
        }
    }
    printf("========================================\n");
    return 0;
}