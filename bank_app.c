#include <stdio.h>
#include <string.h>
struct BankAccount {
    int accNo;
    char name[50];
    float balance;
};
void createAccount(struct BankAccount *acc);
void deposit(struct BankAccount *acc);
void withdraw(struct BankAccount *acc);
void checkBalance(struct BankAccount acc);

int main() {
    struct BankAccount account;
    int choice;
    int isAccountCreated = 0;

    while (1) {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createAccount(&account);
            isAccountCreated = 1;
            break;

        case 2:
            if (isAccountCreated)
                deposit(&account);
            else
                printf("Please create an account first.\n");
            break;
case 3:
            if (isAccountCreated)
                withdraw(&account);
            else
                printf("Please create an account first.\n");
            break;

        case 4:
            if (isAccountCreated)
                checkBalance(account);
            else
                printf("Please create an account first.\n");
            break;

        case 5:
            printf("Thank you for using the Bank Management System.\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
void createAccount(struct BankAccount *acc) {
    printf("\nEnter Account Number: ");
    scanf("%d", &acc->accNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", acc->name);
    printf("Enter Initial Balance: ");
    scanf("%f", &acc->balance);

    printf("\nAccount created successfully!\n");
}
void deposit(struct BankAccount *acc) {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);

    acc->balance += amount;
    printf("Amount deposited successfully!\n");
}
void withdraw(struct BankAccount *acc) {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > acc->balance) {
        printf("Insufficient balance!\n");
    } else {
        acc->balance -= amount;
        printf("Amount withdrawn successfully!\n");
    }
}
void checkBalance(struct BankAccount acc) {
    printf("\n----- Account Details -----\n");
    printf("Account Number: %d\n", acc.accNo);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
}