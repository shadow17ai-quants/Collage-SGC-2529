#include <stdio.h>
#include <string.h>

#define MAX_STOCKS 5
#define SYM_LEN 8

// Hardcoded stock data
char symbols[MAX_STOCKS][SYM_LEN] = {"AAPL", "NVDA", "MSFT", "GOOGL", "AMZN"};
double prices[MAX_STOCKS] = {192.53, 135.21, 420.72, 175.89, 186.34};

// Function prototype
int search_by_symbol(const char *query);

int main() {
    char input[SYM_LEN];

    printf("\n====================================\n");
    printf("   STOCK REGISTRY SEARCH\n");
    printf("====================================\n");
    printf("Available symbols: AAPL, NVDA, MSFT, GOOGL, AMZN\n\n");

    printf("Enter stock symbol: ");
    scanf("%s", input);

    int index = search_by_symbol(input);

    if (index != -1) {
        printf("\n✅ Found: %s at $%.2f\n", symbols[index], prices[index]);
    } else {
        printf("\n❌ Symbol '%s' not found.\n", input);
    }

    printf("====================================\n");
    return 0;
}

// Returns index of matching symbol, or -1 if not found
int search_by_symbol(const char *query) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(symbols[i], query) == 0) {
            return i;
        }
    }
    return -1;
}