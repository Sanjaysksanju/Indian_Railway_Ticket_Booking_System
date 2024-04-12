#include <stdio.h>      // Include standard input/output library
#include <string.h>     // Include string handling library

// Structure to represent a ticket booking
struct TicketBooking {
    char destination[20];   // Member to store the destination
    int numPersons;         // Member to store the number of persons booking tickets
    int ticketPrice;        // Price of the ticket
};
s
// Function to book a ticket
void bookTicket(struct TicketBooking booking, char paymentMethod[], char paymentDetails[]) {
    int totalCost = booking.numPersons * booking.ticketPrice; // Calculate total cost
    // Print the number of tickets booked, the destination, payment method, and total cost
    printf("%d ticket(s) booked to %s\n", booking.numPersons, booking.destination);
    printf("Payment method: %s\n", paymentMethod);
    printf("Payment details: %s\n", paymentDetails);
    printf("Total Cost: %d rupees\n", totalCost);
    printf("Ticket(s) Booked Successfully\nHappy Journey!\n");
}

// Function for UPI payment
void makeUPIpayment(struct TicketBooking booking) {
    int upiOption;
    printf("\nChoose UPI payment method:\n1) Scan QR code\n2) Enter UPI ID\nEnter your option: ");
    scanf("%d", &upiOption);
    char upiDetails[100];
    switch (upiOption) {
        case 1:
            strcpy(upiDetails, "Scan QR code");
            break;
        case 2:
            printf("Enter your UPI ID: ");
            scanf("%s", upiDetails);
            break;
        default:
            printf("Invalid option for UPI payment method.\n");
            return;
    }
    bookTicket(booking, "UPI", upiDetails); // Book the ticket using UPI payment
}

// Function for card payment
void makeCardPayment(struct TicketBooking booking) {
    char cardNumber[20];
    printf("\nEnter your card number: ");
    scanf("%s", cardNumber);
    char pin[5];
    printf("Enter your PIN: ");
    scanf("%s", pin);
    bookTicket(booking, "Card", cardNumber); // Book the ticket using card payment
}

// Function for cash payment
void makeCashPayment(struct TicketBooking booking) {
    bookTicket(booking, "Cash", "Paid in cash"); // Book the ticket using cash payment
}

// Function to handle payment options
void paymentOptions(struct TicketBooking booking) {
    int paymentOption;
    printf("\nChoose payment option:\n1) UPI Payment\n2) Card Payment\n3) Cash Payment\nEnter your option: ");
    scanf("%d", &paymentOption);

    switch (paymentOption) {
        case 1:
            printf("UPI Payment selected.\n");
            makeUPIpayment(booking); // Proceed with UPI payment
            break;
        case 2:
            printf("Card Payment selected.\n");
            makeCardPayment(booking); // Proceed with card payment
            break;
        case 3:
            printf("Cash Payment selected.\n");
            makeCashPayment(booking); // Proceed with cash payment
            break;
        default:
            printf("Invalid option. Please select a valid payment option.\n");
            return;
    }
}

int main() {
    int MenuOption;

    // Start of main loop
    do {
        printf("\nHere are the list of destination places\n1) Ramanagara\n2) Maddur\n3) Mandya\n4) Mysuru\n5) Exit\nEnter your option: ");
        scanf("%d", &MenuOption);

        if (MenuOption < 1 || MenuOption > 5) { // Validate menu option
            printf("Invalid option\nplease enter correct option\n");
            continue;
        }

        if (MenuOption == 5) { // Exit loop if the user chooses to exit
            printf("Happy journey\n");
            break;
        }

        int numPersons;
        printf("How many persons are booking tickets? ");
        scanf("%d", &numPersons);

        if (numPersons <= 0) { // Validate number of persons
            printf("Invalid number of persons. Please enter a valid number.\n");
            continue;
        }

        struct TicketBooking booking;

        // Assign destination and ticket price based on user's choice
        switch (MenuOption) {
            case 1:
                strcpy(booking.destination, "Ramanagara");
                booking.ticketPrice = 25;
                break;
            case 2:
                strcpy(booking.destination, "Maddur");
                booking.ticketPrice = 50;
                break;
            case 3:
                strcpy(booking.destination, "Mandya");
                booking.ticketPrice = 100;
                break;
            case 4:
                strcpy(booking.destination, "Mysuru");
                booking.ticketPrice = 150;
                break;
        }

        booking.numPersons = numPersons;

        paymentOptions(booking); // Pass booking details to payment function

    } while (MenuOption != 5); // End of main loop

    return 0;
}
