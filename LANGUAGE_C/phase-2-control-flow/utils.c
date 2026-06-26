#include <stdio.h>
#include <string.h>

// Function prototypes
double get_positive_double(const char *prompt);
int get_positive_int(const char *prompt);
void get_string(const char *prompt, char *buf, int maxlen);

// Get a positive double from user
double get_positive_double(const char *prompt) {
    double value;
    int valid;

    do {
        printf("%s", prompt);
        valid = scanf("%lf", &value);

        // Clear input buffer
        while (getchar() != '\n');

        if (valid != 1 || value <= 0) {
            printf("❌ Error: Please enter a positive number.\n");
        }
    } while (valid != 1 || value <= 0);

    return value;
}

// Get a positive integer from user
int get_positive_int(const char *prompt) {
    int value;
    int valid;

    do {
        printf("%s", prompt);
        valid = scanf("%d", &value);

        // Clear input buffer
        while (getchar() != '\n');

        if (valid != 1 || value <= 0) {
            printf("❌ Error: Please enter a positive integer.\n");
        }
    } while (valid != 1 || value <= 0);

    return value;
}

// Get a string from user safely
void get_string(const char *prompt, char *buf, int maxlen) {
    printf("%s", prompt);
    fgets(buf, maxlen, stdin);

    // Remove trailing newline
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }
}