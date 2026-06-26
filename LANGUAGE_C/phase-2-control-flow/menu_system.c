#include <stdio.h>

double balance = 0.0;  // Global variable (shared across all functions)

// Function prototypes
void deposit();
void withdraw();
void check_balance();
int get_menu_choice();

int main() {
    int choice;

    printf("\n====================================\n");
    printf("     WELCOME TO AETHERVAULT BANK\n");
    printf("====================================\n\n");

    while (1) {
        choice = get_menu_choice();

        switch (choice) {
            case 1:
                deposit();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                check_balance();
                break;
            case 4:
                printf("\n✅ Thank you for using AetherVault Bank!\n");
                printf("   Final balance: $%.2f\n", balance);
                printf("====================================\n\n");
                return 0;  // Exit program cleanly
            default:
                printf("\n❌ Invalid choice. Please enter 1-4.\n");
        }
    }
}

int get_menu_choice() {
    int choice;
    printf("\n--- MENU ---\n");
    printf("1. Deposit Cash\n");
    printf("2. Withdraw Cash\n");
    printf("3. Check Balance\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void deposit() {
    double amount;
    do {
        printf("Enter amount to deposit (must be > 0): ");
        scanf("%lf", &amount);
        if (amount <= 0) {
            printf("❌ Error: Amount must be positive.\n");
        }
    } while (amount <= 0);

    balance += amount;
    printf("✅ Deposited $%.2f. New balance: $%.2f\n", amount, balance);
}

void withdraw() {
    double amount;
    do {
        printf("Enter amount to withdraw (must be > 0): ");
        scanf("%lf", &amount);
        if (amount <= 0) {
            printf("❌ Error: Amount must be positive.\n");
        } else if (amount > balance) {
            printf("❌ Error: Insufficient funds. Your balance is $%.2f\n", balance);
        }
    } while (amount <= 0 || amount > balance);

    balance -= amount;
    printf("✅ Withdrew $%.2f. New balance: $%.2f\n", amount, balance);
}

void check_balance() {
    printf("\n💰 Your current balance is: $%.2f\n", balance);
}