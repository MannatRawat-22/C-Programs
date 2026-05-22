#include <stdio.h>

int main() {
    int choice;
    float balance = 1000, amount;

    printf("===== ATM MENU =====\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("Balance = %.2f", balance);
            break;

        case 2:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            balance += amount;

            printf("Updated Balance = %.2f", balance);
            break;

        case 3:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if(amount <= balance) {
                balance -= amount;
                printf("Updated Balance = %.2f", balance);
            }
            else {
                printf("Insufficient Balance");
            }

            break;

        default:
            printf("Invalid Choice");
    }

    return 0;
}