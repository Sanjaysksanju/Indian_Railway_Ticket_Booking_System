#include "ticket.h" // Including custom header file for function prototypes

// Function to handle payment process
void processPayment(int totalCost) {
    int paymentMethod; // Variable to store the selected payment method

    // Loop until a valid payment method is selected
    do {
        printf("\nPlease select your payment method:\n");
        printf("1. Cash\n");
        printf("2. Debit Card\n");
        printf("3. Mobile Payment\n");
        printf("4. QR Code Payment\n");
        printf("5. Online Payment\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &paymentMethod); // Reading user input for payment method

        // Check if the entered payment method is within the valid range
        if (paymentMethod < 1 || paymentMethod > 5) {
            printf("Invalid payment method. Please try again.\n"); // Error message for invalid input
        }
    } while (paymentMethod < 1 || paymentMethod > 5); // Loop until valid input is entered

    // Process the payment based on the selected method
    switch (paymentMethod) {
        case 1:
            printf("You have selected: Cash\n");
            printf("Please pay Rupees %d at the counter.\n", totalCost); // Displaying payment instructions for cash
            break;
        case 2:
            printf("You have selected: Debit Card\n");
            printf("Please insert your card\n");
            // Ask for PIN
            int pin;
            do {
                printf("Please enter your PIN : ");
                scanf("%d", &pin); // Reading user input for PIN
                // Validate PIN
                if (!validatePIN(pin)) { // Using validatePIN function to validate PIN
                    printf("Invalid PIN. Please enter a valid PIN.\n"); // Error message for invalid PIN
                }
            } while (!validatePIN(pin)); // Loop until valid PIN is entered
            // Process payment with PIN verification
            printf("Payment of Rupees %d successfully processed.\n", totalCost); // Displaying success message
            break;
        // Cases 3 to 5: Displaying payment instructions for mobile payment, QR code payment, and online payment
        case 3:
            printf("You have selected: Mobile Payment\n");
            printf("Please scan the QR code displayed on your mobile to complete the payment of Rupees %d.\n", totalCost);
            break;
        case 4:
            printf("You have selected: QR Code Payment\n");
            printf("Please scan the QR code displayed at the counter to make the payment of Rupees %d.\n", totalCost);
            break;
        case 5:
            printf("You have selected: Online Payment\n");
            printf("Please log in to your online payment account to complete the transaction of Rupees %d.\n", totalCost);
            break; // exit the loop
    }
}
