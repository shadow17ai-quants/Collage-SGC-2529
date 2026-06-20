#include <stdio.h>
#include <math.h>   // for pow(), sqrt(), fabs()

int main() {
    double price = 100.0;          // base stock price
    double volatility = 0.02;      // 2% daily volatility

    // Compute risk metrics
    double daily_variance = pow(volatility, 2);        // vol^2
    double daily_std_dev = sqrt(daily_variance);       // sqrt(variance)
    double abs_daily_move = fabs(price * volatility);  // absolute expected move

    // Print with 6 decimal places (as requested)
    printf("\n===== Risk Engine Calculation =====\n");
    printf(" Base Price:         %8.2f\n", price);
    printf(" Volatility:          %8.6f\n", volatility);
    printf("----------------------------------\n");
    printf(" Daily Variance:      %8.6f  (pow(vol,2) — used for scaling)\n", daily_variance);
    printf(" Daily Std Dev:       %8.6f  (sqrt(variance) — used for confidence intervals)\n", daily_std_dev);
    printf(" Abs Daily Move:      %8.6f  (fabs(price*vol) — max expected daily change)\n", abs_daily_move);
    printf("==================================\n\n");

    // Link to AetherVault Risk Engine
    printf(" In AetherVault Trader:\n");
    printf("   - Variance  → portfolio volatility weighting\n");
    printf("   - Std Dev   → risk score (1-10 scale)\n");
    printf("   - Abs Move  → position sizing limits\n");

    return 0;
}




