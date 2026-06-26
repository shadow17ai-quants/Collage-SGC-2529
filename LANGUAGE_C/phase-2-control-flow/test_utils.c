#include <stdio.h>
#include "utils.c"  // Include the utilities

int main() {
    printf("\n=== Testing Input Validation Utilities ===\n\n");

    // Test 1: Positive double
    double price = get_positive_double("Enter stock price: ");
    printf("✅ You entered: $%.2f\n\n", price);

    // Test 2: Positive integer
    int quantity = get_positive_int("Enter quantity: ");
    printf("✅ You entered: %d\n\n", quantity);

    // Test 3: String
    char symbol[10];
    get_string("Enter stock symbol: ", symbol, sizeof(symbol));
    printf("✅ You entered: %s\n\n", symbol);

    return 0;
}