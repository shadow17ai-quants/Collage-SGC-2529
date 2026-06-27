#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STOCKS 5
#define SYM_LEN 8

// --- Data ---
char symbols[MAX_STOCKS][SYM_LEN] = {"AAPL", "NVDA", "MSFT", "GOOGL", "AMZN"};
double prices[MAX_STOCKS] = {192.53, 135.21, 420.72, 175.89, 186.34};
int quantities[MAX_STOCKS] = {10, 5, 8, 3, 12};

// --- Function Prototypes ---
int search_by_symbol(const char *query);
int read_symbol(char *buf, int maxlen);
void build_row(char *out, int outlen, const char *sym, int qty, double price, double value);
int get_positive_int(const char *prompt);
void show_menu();
void view_portfolio();
void search_stock();
void add_holding();

// --- Main Program ---
int main() {
    int choice;

    printf("\n====================================\n");
    printf("   INTEGRATED PORTFOLIO SYSTEM\n");
    printf("====================================\n");

    while (1) {
        show_menu();
        choice = get_positive_int("Enter your choice: ");

        switch (choice) {
            case 1:
                view_portfolio();
                break;
            case 2:
                search_stock();
                break;
            case 3:
                add_holding();
                break;
            case 4:
                printf("\n✅ Exiting system. Goodbye!\n");
                printf("====================================\n");
                return 0;
            default:
                printf("❌ Invalid choice. Please enter 1–4.\n");
        }
    }
}

// --- Menu Display ---
void show_menu() {
    printf("\n--- MENU ---\n");
    printf("1. View Portfolio\n");
    printf("2. Search Stock\n");
    printf("3. Add Holding (hardcoded)\n");
    printf("4. Quit\n");
}

// --- View Portfolio ---
void view_portfolio() {
    char row[100];

    printf("\n====================================\n");
    printf("   PORTFOLIO TABLE\n");
    printf("====================================\n");
    printf("%-8s %6s %10s %12s %12s\n", "Symbol", "Qty", "Price", "Value", "P&L");
    printf("------------------------------------\n");

    double total_value = 0.0;
    for (int i = 0; i < MAX_STOCKS; i++) {
        double value = quantities[i] * prices[i];
        double pl = value * 0.05;  // simulate 5% gain (simplified)
        build_row(row, sizeof(row), symbols[i], quantities[i], prices[i], value);
        printf("%s %+12.2f\n", row, pl);
        total_value += value;
    }

    printf("------------------------------------\n");
    printf("Total Portfolio Value: $%.2f\n", total_value);
    printf("====================================\n");
}

// --- Search Stock ---
void search_stock() {
    char input[SYM_LEN];
    printf("\nEnter stock symbol: ");
    read_symbol(input, sizeof(input));

    int idx = search_by_symbol(input);
    if (idx != -1) {
        printf("✅ Found: %s at $%.2f (Qty: %d)\n",
               symbols[idx], prices[idx], quantities[idx]);
    } else {
        printf("❌ Symbol '%s' not found.\n", input);
    }
}

// --- Add Holding (hardcoded) ---
void add_holding() {
    // In a real system, this would prompt for symbol, qty, price.
    // For now, just add a dummy holding.
    printf("\n🔧 This feature is a placeholder.\n");
    printf("   Adding dummy holding: TSLA | 20 shares | $250.00\n");
}

// --- Utility: search_by_symbol ---
int search_by_symbol(const char *query) {
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (strcmp(symbols[i], query) == 0) {
            return i;
        }
    }
    return -1;
}

// --- Utility: read_symbol (safe, uppercase) ---
int read_symbol(char *buf, int maxlen) {
    fgets(buf, maxlen, stdin);
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
        len--;
    }
    for (size_t i = 0; i < len; i++) {
        buf[i] = toupper(buf[i]);
    }
    if (len == 0 || len > 6) {
        return 0;
    }
    return 1;
}

// --- Utility: build_row (formatted table row) ---
void build_row(char *out, int outlen, const char *sym, int qty, double price, double value) {
    snprintf(out, outlen, "%-8s %6d %10.2f %12.2f", sym, qty, price, value);
}

// --- Utility: get_positive_int (from Day 5) ---
int get_positive_int(const char *prompt) {
    int value;
    int valid;
    do {
        printf("%s", prompt);
        valid = scanf("%d", &value);
        while (getchar() != '\n');
        if (valid != 1 || value <= 0) {
            printf("❌ Error: Please enter a positive integer.\n");
        }
    } while (valid != 1 || value <= 0);
    return value;
}