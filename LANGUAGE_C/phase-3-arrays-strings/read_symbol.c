#include <stdio.h>
#include <string.h>
#include <ctype.h>   // for toupper()

// Function prototype
int read_symbol(char *buf, int maxlen);

int main() {
    char symbol[10];

    printf("\n====================================\n");
    printf("   SYMBOL INPUT TEST\n");
    printf("====================================\n");

    while (1) {
        printf("Enter stock symbol (1-6 chars): ");
        if (read_symbol(symbol, sizeof(symbol))) {
            printf("✅ Valid symbol: %s\n", symbol);
            break;
        } else {
            printf("❌ Invalid input. Try again.\n");
        }
    }

    printf("====================================\n");
    return 0;
}

// Reads a symbol, strips newline, converts to uppercase, validates length
int read_symbol(char *buf, int maxlen) {
    // 1. Read input with fgets
    fgets(buf, maxlen, stdin);

    // 2. Remove trailing newline
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
        len--;
    }

    // 3. Convert to uppercase
    for (size_t i = 0; i < len; i++) {
        buf[i] = toupper(buf[i]);
    }

    // 4. Validate: not empty, not too long (max 6 chars)
    if (len == 0 || len > 6) {
        return 0;  // failure
    }

    return 1;  // success
}