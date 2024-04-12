#include <stdio.h>
#include <string.h>

// Structure to represent a ticket booking
struct TicketBooking {
    char destination[20];
    int numPersons;
    int ticketPrice; // Price of the ticketss
};

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
    bookTicket(booking, "UPI", upiDetails);
}

// Function for card payment
void makeCardPayment(struct TicketBooking booking) {
    char cardNumber[20];
    printf("\nEnter your card number: ");
    scanf("%s", cardNumber);
    char pin[5];
    printf("Enter your PIN: ");
    scanf("%s", pin);
    bookTicket(booking, "Card", cardNumber);
}

// Function for cash payment
void makeCashPayment(struct TicketBooking booking) {
    bookTicket(booking, "Cash", "Paid in cash");
}

// Function to handle payment options
void paymentOptions(struct TicketBooking booking) {
    int paymentOption;
    printf("\nChoose payment option:\n1) UPI Payment\n2) Card Payment\n3) Cash Payment\nEnter your option: ");
    scanf("%d", &paymentOption);

    switch (paymentOption) {
        case 1:
            printf("UPI Payment selected.\n");
            makeUPIpayment(booking);
            break;
        case 2:
            printf("Card Payment selected.\n");
            makeCardPayment(booking);
            break;
        case 3:
            printf("Cash Payment selected.\n");
            makeCashPayment(booking);
            break;
        default:
            printf("Invalid option. Please select a valid payment option.\n");
            return;
    }
}

int main() {
    int MenuOption;

    do {
        printf("\nHere are the list of destination places\n1) Ramanagara\n2) Maddur\n3) Mandya\n4) Mysuru\n5) Exit\nEnter your option: ");
        scanf("%d", &MenuOption);

        if (MenuOption < 1 || MenuOption > 5) {
            printf("Invalid option\nplease enter correct option\n");
            continue;
        }

        if (MenuOption == 5) {
            printf("Happy journey\n");
            break;
        }

        int numPersons;
        printf("How many persons are booking tickets? ");
        scanf("%d", &numPersons);

        if (numPersons <= 0) {
            printf("Invalid number of persons. Please enter a valid number.\n");
            continue;
        }

        struct TicketBooking booking;

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

    } while (MenuOption != 5);

    return 0;
}
