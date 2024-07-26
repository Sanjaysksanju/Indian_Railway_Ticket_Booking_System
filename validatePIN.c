#include "ticket.h" // Including custom header file for function prototypes

// Function to validate PIN input
int validatePIN(int pin) {
    int count = 0; // Variable to count the number of digits in the PIN

    // Loop until the PIN becomes 0
    while (pin != 0) {
        pin /= 10; // Removing the last digit of the PIN
        ++count; // Incrementing the count of digits continously
    }

    // Returning true if the number of digits is less than or equal to 6, else false
    return count <= 6;
}
