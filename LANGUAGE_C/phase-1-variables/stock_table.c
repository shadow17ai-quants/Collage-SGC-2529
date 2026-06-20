#include <stdio.h>

int main() {
    // Hardcoded stock data (no arrays yet)
    char sym1[] = "AAPL", sym2[] = "NVDA", sym3[] = "MSFT";
    char sym4[] = "GOOGL", sym5[] = "AMZN";

    double price1 = 192.53, price2 = 135.21, price3 = 420.72;
    double price4 = 175.89, price5 = 186.34;

    double change1 = 2.15, change2 = -1.47, change3 = 0.83;
    double change4 = -0.26, change5 = 3.41;

    // Print header
    printf("\n");
    printf("=====================================\n");
    printf("  Stock Price Snapshot\n");
    printf("=====================================\n");
    printf("%-8s %10s %10s\n", "Symbol", "Price", "Change%%");
    printf("-------------------------------------\n");

    // Print rows
    printf("%-8s %10.2f %+8.2f%%\n", sym1, price1, change1);
    printf("%-8s %10.2f %+8.2f%%\n", sym2, price2, change2);
    printf("%-8s %10.2f %+8.2f%%\n", sym3, price3, change3);
    printf("%-8s %10.2f %+8.2f%%\n", sym4, price4, change4);
    printf("%-8s %10.2f %+8.2f%%\n", sym5, price5, change5);

    printf("-------------------------------------\n");
    printf("  Data as of 20 Jun 2026\n");
    printf("=====================================\n");

    return 0;
}