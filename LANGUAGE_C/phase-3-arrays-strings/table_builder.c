#include <stdio.h>

// Function prototype
void build_row(char *out, int outlen, const char *sym, int qty, double price, double value);

int main() {
    char row[100];

    printf("\n====================================\n");
    printf("   PORTFOLIO TABLE DEMO\n");
    printf("====================================\n");
    printf("%-8s %6s %10s %12s\n", "Symbol", "Qty", "Price", "Value");
    printf("------------------------------------\n");

    // Hardcoded holdings
    build_row(row, sizeof(row), "AAPL", 10, 192.53, 1925.30);
    printf("%s\n", row);
    build_row(row, sizeof(row), "NVDA", 5, 135.21, 676.05);
    printf("%s\n", row);
    build_row(row, sizeof(row), "MSFT", 8, 420.72, 3365.76);
    printf("%s\n", row);
    build_row(row, sizeof(row), "GOOGL", 3, 175.89, 527.67);
    printf("%s\n", row);
    build_row(row, sizeof(row), "AMZN", 12, 186.34, 2236.08);
    printf("%s\n", row);

    printf("====================================\n");
    return 0;
}

// Builds a formatted table row using snprintf
void build_row(char *out, int outlen, const char *sym, int qty, double price, double value) {
    snprintf(out, outlen, "%-8s %6d %10.2f %12.2f", sym, qty, price, value);
}