#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char date[20];
    char category[30];
    float amount;
};

void addExpense() {
    FILE *fp;
    struct Expense e;

    fp = fopen("expenses.txt", "a");

    printf("Enter Date (DD/MM/YYYY): ");
    scanf("%s", e.date);

    printf("Enter Category: ");
    scanf("%s", e.category);

    printf("Enter Amount: ");
    scanf("%f", &e.amount);

    fprintf(fp, "%s %s %.2f\n", e.date, e.category, e.amount);

    fclose(fp);

    printf("\nExpense Added Successfully!\n");
}

void viewExpenses() {
    FILE *fp;
    struct Expense e;

    fp = fopen("expenses.txt", "r");

    if (fp == NULL) {
        printf("No expenses found.\n");
        return;
    }

    printf("\nDate\t\tCategory\tAmount\n");
    printf("---------------------------------------\n");

    while (fscanf(fp, "%s %s %f", e.date, e.category, &e.amount) != EOF) {
        printf("%s\t%s\t\t%.2f\n", e.date, e.category, e.amount);
    }

    fclose(fp);
}

void totalExpenses() {
    FILE *fp;
    struct Expense e;
    float total = 0;

    fp = fopen("expenses.txt", "r");

    if (fp == NULL) {
        printf("No expenses found.\n");
        return;
    }

    while (fscanf(fp, "%s %s %f", e.date, e.category, &e.amount) != EOF) {
        total += e.amount;
    }

    fclose(fp);

    printf("\nTotal Expenses: ₹%.2f\n", total);
}

int main() {
    int choice;

    do {
        printf("\n===== EXPENSE TRACKER =====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                totalExpenses();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice!\n");
        }
    } while(choice != 4);

    return 0;
}