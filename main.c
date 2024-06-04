#include <stdio.h> // Including standard input-output header file
#include "ticket.h" // Including custom header file for ticket functions
#include "displayDestinations.c" // Including custom function to display destinations
#include "calculateTotalCost.c" // Including custom function to calculate total cost
#include "validatePIN.c" // Including custom function to validate PIN
#include "processPayment.c" // Including custom function to process payment

int main() { // Main function declaration

    int choice, numTickets, totalCost; // Declaration of variables for user input and calculations
    int ticketPrice = 50; // Initial ticket price for Kengeri

    do { // Start of do-while loop for ticket booking system

        // Display the list of available destinations
        displayDestinations();

        // Prompt user to choose a destination
        printf("\nPlease select your destination (1-7): ");
        scanf("%d", &choice); // Reading user input for destination choice

        // Process the user's choice
        switch (choice) { // Start of switch statement based on user choice
            case 1:
                printf("\nYou have selected: Kengeri\n"); // Displaying chosen destination
                break;
            case 2:
                printf("\nYou have selected: Ramanagara\n"); // Displaying chosen destination
                break;
            // Cases 3 to 6: Displaying chosen destinations
            case 3:
                printf("\nYou have selected: Channapatana\n");
                break;
            case 4:
                printf("\nYou have selected: Maddur\n");
                break;
            case 5:
                printf("\nYou have selected: Mandya\n");
                break;
            case 6:
                printf("\nYou have selected: Mysuru\n");
                break;
            case 7:
                printf("\nExiting the ticket booking system. Thank you for using our service!\n"); // Exiting message
                continue; // Skip the payment part and continue with the loop
            default:
                printf("\nInvalid choice. Please try again.\n"); // Displaying error for invalid choice
                continue; // Continuing the loop
        }

        // Increase the ticket price by 25% for the next destination (excluding Kengeri)
        if (choice != 1) {
            ticketPrice = ticketPrice * 1.25; // Calculating new ticket price
        }

        // Prompt user to enter the number of tickets they want to book (1-6)
        do {
            printf("Please enter the number of tickets you want to book (maximum 6): ");
            scanf("%d", &numTickets); // Reading user input for number of tickets

            // Check if the entered number of tickets is within the valid range
            if (numTickets < 1 || numTickets > 6) {
                printf("Invalid number of tickets. Please enter a number between 1 and 6.\n"); // Error message for invalid input
            }
        } while (numTickets < 1 || numTickets > 6); // Loop until valid input is entered

        // Calculate the total cost of tickets
        totalCost = calculateTotalCost(numTickets, ticketPrice); // Calculating total cost

        // Display the total cost of tickets
        printf("\nThe total cost of tickets for %d person(s) is: Rupees %d\n", numTickets, totalCost); // Displaying total cost

        // Process payment
        processPayment(totalCost); // Processing payment for tickets

        // Wishing line
        printf("\nThank you for booking tickets with us. Have a safe journey!\n"); // Farewell message

    } while (choice != 7); // End of do-while loop

    return 0; // Indicate successful execution
}
