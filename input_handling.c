#include <stdio.h>
#include <ctype.h>
#include <stdlib.h> // For atof
#include "input_handling.h"

// Function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to remove spaces from a string
void remove_spaces(char *str) {
    char *dst = str;
    while (*str) {
        if (!isspace((unsigned char)*str)) {
            *dst++ = *str;
        }
        str++;
    }
    *dst = '\0';
}

// Function to check if a string contains only digits
int is_digits(const char *str) {
    while (*str) {
        if (!isdigit((unsigned char)*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
