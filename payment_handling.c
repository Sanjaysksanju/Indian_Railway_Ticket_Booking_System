#include <stdio.h>
#include <string.h>
#include "input_handling.h"
#include "payment_handling.h"

// Function to handle payment
void handle_payment(int payment_method, float total_cost, char *card_number, char *card_expiry, char *card_cvv, char *paypal_email, char *upi_id, int *pin) {
    switch (payment_method) {
        case 1:
        case 2:
            while (1) {
                printf("Please enter your card number (16 digits, no spaces): ");
                fgets(card_number, 20, stdin);
                card_number[strcspn(card_number, "\n")] = '\0'; // Remove newline character
                remove_spaces(card_number);
                if (strlen(card_number) != 16 || !is_digits(card_number)) {
                    printf("Invalid card number. It should be 16 digits without spaces.\n");
                    continue;
                }
                printf("Please enter your card expiry date (MM/YY): ");
                fgets(card_expiry, 8, stdin);
                card_expiry[strcspn(card_expiry, "\n")] = '\0'; // Remove newline character
                printf("Please enter your card CVV (3 digits): ");
                fgets(card_cvv, 4, stdin);
                card_cvv[strcspn(card_cvv, "\n")] = '\0'; // Remove newline character
                break;
            }
            break;
        case 3:
            printf("Please enter your PayPal email address: ");
            fgets(paypal_email, 50, stdin);
            paypal_email[strcspn(paypal_email, "\n")] = '\0'; // Remove newline character
            break;
        case 4:
            printf("Please enter your UPI ID: ");
            fgets(upi_id, 50, stdin);
            upi_id[strcspn(upi_id, "\n")] = '\0'; // Remove newline character
            while (1) {
                printf("Please enter your UPI PIN to proceed with the payment: ");
                if (scanf("%d", pin) != 1) {
                    printf("Invalid input. Please enter a valid PIN.\n");
                    clear_input_buffer(); // Clear the input buffer
                    continue;
                }
                clear_input_buffer(); // Clear any remaining input
                break;
            }
            break;
    }

    printf("Payment of Rupees %.2f processed successfully.\n", total_cost);
}
