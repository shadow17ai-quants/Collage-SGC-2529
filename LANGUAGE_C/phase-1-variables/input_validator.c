#include <stdio.h>

// Helper to clear input buffer after scanf
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    double balance = 0.0;
    double amount = 0.0;
    int valid;

    // ---- Ask for cash balance (must be > 0) ----
    do {
        printf("Enter your starting cash balance (positive amount): ");
        valid = scanf("%lf", &balance);
        clear_buffer();  // clear leftover newline / invalid chars

        if (valid != 1 || balance <= 0) {
            printf(" ERROR: Please enter a positive number.\n");
        }
    } while (valid != 1 || balance <= 0);

    // Display with formatting
    printf(" Balance set to $%.2f\n\n", balance);

    // ---- Ask for transaction amount (must be <= balance and > 0) ----
    do {
        printf("Enter transaction amount (0 < amount <= %.2f): ", balance);
        valid = scanf("%lf", &amount);
        clear_buffer();

        if (valid != 1 || amount <= 0) {
            printf(" ERROR: Amount must be positive.\n");
        } else if (amount > balance) {
            printf(" ERROR: Amount exceeds balance of %.2f.\n", balance);
        }
    } while (valid != 1 || amount <= 0 || amount > balance);

    // Confirm success
    balance -= amount;
    printf("\n Transaction successful! Remaining balance: $%.2f\n", balance);

    return 0;
}