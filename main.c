#include <stdio.h>
#include <string.h>
#include "ticket_booking.h"

// Include function declarations from other files
#include "destinations.c"
#include "persons_booking.c"
#include "payment_options.c"

int main() {
    int MenuOption;

    do {
        displayDestinations(); // Display destinations

        printf("Enter your option: ");
        scanf("%d", &MenuOption);

        if (MenuOption < 1 || MenuOption > 5) {
            printf("Invalid option\nplease enter correct option\n");
            continue;
        }

        if (MenuOption == 5) {
            printf("Happy journey\n");
            break;
        }

        int numPersons = getNumberOfPersons(); // Get number of persons booking tickets

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
