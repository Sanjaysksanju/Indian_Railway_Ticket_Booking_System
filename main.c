#include <stdio.h>            // Include standard input/output library
#include <string.h>           // Include string handling library
#include "ticket_booking.h"   // Include the header file for function declarations

// Include function definitions from other files
#include "destinations.c"
#include "persons_booking.c"
#include "payment_options.c"

int main() {
    int MenuOption;   // Declare variable for menu option

    // Start of main loop
    do {
        displayDestinations();   // Display destinations

        printf("Enter your option: ");
        scanf("%d", &MenuOption);   // Read user's menu option

        if (MenuOption < 1 || MenuOption > 5) {   // Validate menu option
            printf("Invalid option\nplease enter correct option\n");
            continue;
        }

        if (MenuOption == 5) {   // Exit loop if the user chooses to exit
            printf("Happy journey\n");
            break;
        }

        int numPersons = getNumberOfPersons();   // Get number of persons booking tickets

        if (numPersons <= 0) {   // Validate number of persons
            printf("Invalid number of persons. Please enter a valid number.\n");
            continue;
        }

        struct TicketBooking booking;   // Declare struct variable for ticket booking

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

        booking.numPersons = numPersons;   // Assign number of persons to booking

        paymentOptions(booking);   // Pass booking details to payment function

    } while (MenuOption != 5);   // End of main loop

    return 0;
}
