#include <stdio.h>
#include <string.h>
#include "ticket_booking.h"

// Function to handle payment options
void paymentOptions(struct TicketBooking booking) {
    int paymentOption;
    printf("Choose payment option:\n1) UPI Payment\n2) Card Payment\n3) Cash Payment\nEnter your option: ");
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
