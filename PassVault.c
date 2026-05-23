#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length;
    
    // character set
    char charset[] = "abcdefghijklmnopqrstuvwxyz"
                      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "0123456789"
                      "!@#$%^&*";

    int charsetSize = sizeof(charset) - 1;

    printf("Enter password length: ");
    scanf("%d", &length);

    // seed random generator
    srand(time(0));

    printf("Generated Password: ");

    for(int i = 0; i < length; i++) {
        int index = rand() % charsetSize;
        printf("%c", charset[index]);
    }

    printf("\n");

    return 0;
}