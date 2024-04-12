#ifndef TICKET_BOOKING_H
#define TICKET_BOOKING_H

// Structure to represent a ticket booking
struct TicketBooking {
    char destination[20];
    int numPersons;
    int ticketPrice; // Price of the ticket
};

// Function declarations
void bookTicket(struct TicketBooking booking, char paymentMethod[], char paymentDetails[]);
void makeUPIpayment(struct TicketBooking booking);
void makeCardPayment(struct TicketBooking booking);
void makeCashPayment(struct TicketBooking booking);
void paymentOptions(struct TicketBooking booking);

#endif
