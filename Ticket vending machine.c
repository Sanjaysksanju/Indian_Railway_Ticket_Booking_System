#include <stdio.h>      // Standard Input/Output library, for printf and scanf functions
#include <string.h>     // String handling library, for strcpy function

// Structure to represent a ticket booking
struct TicketBooking {
    char destination[20];   //// Member to store the fruit Destination name
    int numPersons;         // // Member to store the Number of persons booking tickets
};

// Function to book a ticket
void bookTicket(struct TicketBooking booking) {
    // Print the number of tickets booked and the destination
    printf("%d ticket(s) booked to %s\n", booking.numPersons, booking.destination);
    printf("Ticket(s) Booked Successfully\nHappy Journey!\n");
}

int main() {
    int MenuOption; // Variable for selecting option;

    do {
        // Choose option 1-5 for selecting destination address.
        printf("Here are the list of destination places\n1) Ramanagara\n2) Maddur\n3) Mandya\n4) Mysuru\n5) Exit\nEnter your option: ");
        scanf("%d", &MenuOption);

        // Validate the menu option
        if (MenuOption < 1 || MenuOption > 5) {
            printf("Invalid option\n");
            continue;
        }

        if (MenuOption == 5) {
            printf("Happy journey\n");
            break;
        }

        // Ask the user to input the number of persons
        int numPersons;
        printf("How many persons are booking tickets? ");
        scanf("%d", &numPersons);

        // Validate the number of persons
        if (numPersons <= 0) {
            printf("Invalid number of persons. Please enter a valid number.\n");
            continue;
        }

        // Create a TicketBooking structure for the booking
        struct TicketBooking booking;

        // Assign destination based on user's choice
        switch (MenuOption) {
            case 1:
                strcpy(booking.destination, "Ramanagara");
                break;
            case 2:
                strcpy(booking.destination, "Maddur");
                break;
            case 3:
                strcpy(booking.destination, "Mandya");
                break;
            case 4:
                strcpy(booking.destination, "Mysuru");
                break;
        }

        // Assign the number of persons
        booking.numPersons = numPersons;

        // Book the ticket
        bookTicket(booking);

    } while (MenuOption != 5); // Loop until the user chooses to exit

    return 0;
}
