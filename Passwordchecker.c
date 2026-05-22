#include <stdio.h>
#include <string.h>

int main() {
    char password[50];

    printf("Enter Password: ");
    scanf("%s", password);

    int length = strlen(password);

    if(length < 5)
        printf("Weak Password ❌");

    else if(length < 8)
        printf("Medium Password ⚠️");

    else
        printf("Strong Password ✅");

    return 0;
}