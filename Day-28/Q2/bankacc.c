#include <stdio.h>

struct BankAccount
{
    int accountNumber;
    char name[50];
    float balance;
};

int main()
{
    struct BankAccount account;
    int choice;
    float amount;

    printf("===== CREATE BANK ACCOUNT =====\n");
    printf("Enter Account Number: ");
    scanf("%d", &account.accountNumber);

    getchar(); // Clear input buffer

    printf("Enter Account Holder Name: ");
    fgets(account.name, sizeof(account.name), stdin);

    account.balance = 0;

    while (1)
    {
        printf("\n===== BANK ACCOUNT SYSTEM =====\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Display Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount > 0)
            {
                account.balance += amount;
                printf("Amount deposited successfully.\n");
            }
            else
            {
                printf("Invalid amount.\n");
            }
            break;

        case 2:
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Invalid amount.\n");
            }
            else if (amount > account.balance)
            {
                printf("Insufficient balance.\n");
            }
            else
            {
                account.balance -= amount;
                printf("Withdrawal successful.\n");
            }
            break;

        case 3:
            printf("Current Balance: ₹%.2f\n", account.balance);
            break;

        case 4:
            printf("\n===== ACCOUNT DETAILS =====\n");
            printf("Account Number : %d\n", account.accountNumber);
            printf("Account Holder : %s", account.name);
            printf("Balance         : ₹%.2f\n", account.balance);
            break;

        case 5:
            printf("Thank you for using the Bank Account System.\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}