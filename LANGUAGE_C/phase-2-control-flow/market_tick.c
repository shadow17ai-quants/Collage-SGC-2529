#include <stdio.h>
#include <stdlib.h>   // for rand(), srand()
#include <time.h>     // for time()

// Function prototype
double simulate_tick(double price, double volatility);

int main() {
    // Seed random number generator
    srand(time(NULL));

    double price = 100.0;          // Starting price
    double volatility = 0.02;      // 2% daily volatility

    printf("\n====================================\n");
    printf("   MARKET TICK SIMULATOR\n");
    printf("====================================\n");
    printf(" Starting Price: $%.4f\n", price);
    printf(" Volatility:     %.2f%%\n", volatility * 100);
    printf("------------------------------------\n");

    // Simulate 10 ticks
    for (int i = 1; i <= 10; i++) {
        price = simulate_tick(price, volatility);
        printf(" Tick %2d: $%.4f\n", i, price);
    }

    printf("====================================\n\n");
    return 0;
}

// Simulates one price tick using random walk
double simulate_tick(double price, double volatility) {
    // Generate random change between -volatility and +volatility
    // rand() returns 0 to RAND_MAX
    double change = ((double)rand() / RAND_MAX) * 2.0 - 1.0;  // -1.0 to +1.0
    change = change * volatility * price;  // Scale by volatility and price

    double new_price = price + change;

    // Price cannot go below 0
    if (new_price < 0.01) {
        new_price = 0.01;
    }

    return new_price;
}