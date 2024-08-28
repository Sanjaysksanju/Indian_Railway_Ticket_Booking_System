#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "input_handling.h"
#include "payment_handling.h"
#include "route_handling.h"

// Function to validate integer input
int get_valid_integer_input() {
    int value;
    char buffer[100];

    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error reading input.\n");
            exit(1);
        }
        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Check if the input is a valid integer
        char *endptr;
        value = strtol(buffer, &endptr, 10);
        if (*endptr == '\0') {
            return value; // Valid integer input
        } else {
            printf("Invalid input. Please enter a valid number.\nYour choice:");
        }
    }
}

int main() {
    int source, destination, adult_tickets, child_tickets, payment_method, pin;
    char upi_id[50], paypal_email[50];
    char card_number[20], card_expiry[8], card_cvv[4];
    float ticket_price = 0.0, child_ticket_price = 0.0, total_cost = 0.0;
    char source_address[50], destination_address[50];
    char source_filename[50];

    printf("Welcome to the Ticket Booking System!\n");
    printf("We are here to assist you in booking your tickets.\n");

    while (1) {
        // Source selection
        while (1) {
            printf("\nPlease enter your source address (number):\n");
            printf("1. Kengeri\n");
            printf("2. Ramanagara\n");
            printf("3. Channapatana\n");
            printf("4. Maddur\n");
            printf("5. Mandya\n");
            printf("6. Mysuru\n");
            printf("7. Exit\n");
            printf("Your choice: ");

            source = get_valid_integer_input();

            if (source == 7) {
                printf("Thank you for using our service. Goodbye!\n");
                return 0; // Exit the program
            }

            switch (source) {
                case 1:
                    strcpy(source_address, "Kengeri");
                    strcpy(source_filename, "Kengeri.txt");
                    break;
                case 2:
                    strcpy(source_address, "Ramanagara");
                    strcpy(source_filename, "Ramanagara.txt");
                    break;
                case 3:
                    strcpy(source_address, "Channapatana");
                    strcpy(source_filename, "Channapatana.txt");
                    break;
                case 4:
                    strcpy(source_address, "Maddur");
                    strcpy(source_filename, "Maddur.txt");
                    break;
                case 5:
                    strcpy(source_address, "Mandya");
                    strcpy(source_filename, "Mandya.txt");
                    break;
                case 6:
                    strcpy(source_address, "Mysuru");
                    strcpy(source_filename, "Mysuru.txt");
                    break;
                default:
                    printf("Invalid source address choice. Please enter a number between 1 and 7.\n");
                    continue;
            }
            break; // Break out of the source selection loop if valid
        }

        // Destination selection
        while (1) {
            printf("\nAvailable destinations from %s:\n", source_address);
            display_routes(source_filename);

            printf("Please enter your destination address (number):\n");
            printf("Your choice: ");

            destination = get_valid_integer_input();

            // Check if the destination option is valid
            if (get_ticket_price(source_filename, destination, &ticket_price, &child_ticket_price, destination_address)) {
                break; // Break out of the destination selection loop if valid
            } else {
                printf("Invalid destination choice. Please enter a valid number.\n");
            }
        }

        // Ticket quantity
        while (1) {
            printf("Please enter the number of adult tickets you want to book: ");
            adult_tickets = get_valid_integer_input();

            printf("Please enter the number of child tickets you want to book: ");
            child_tickets = get_valid_integer_input();

            if (adult_tickets < 0 || child_tickets < 0) {
                printf("Invalid number of tickets. Please enter non-negative numbers.\n");
                continue;
            }
            break; // Break out of the ticket quantity loop if valid
        }

        total_cost = (ticket_price * adult_tickets) + (child_ticket_price * child_tickets);
        printf("\nThe total cost of tickets is: Rupees %.2f\n", total_cost);

        // Payment method
        while (1) {
            printf("\nProcessing your payment...\n");
            printf("Select payment method:\n");
            printf("1. Credit Card\n");
            printf("2. Debit Card\n");
            printf("3. PayPal\n");
            printf("4. UPI\n");
            printf("Enter your choice (1-4): ");

            payment_method = get_valid_integer_input();

            if (payment_method < 1 || payment_method > 4) {
                printf("Invalid payment method. Please enter a number between 1 and 4.\n");
                continue;
            }
            break; // Break out of the payment method loop if valid
        }

        handle_payment(payment_method, total_cost, card_number, card_expiry, card_cvv, paypal_email, upi_id, &pin);

        // Print ticket
        time_t t;
        time(&t);
        struct tm *timeinfo = localtime(&t);
        char date_time[30];
        strftime(date_time, sizeof(date_time), "%Y-%m-%d %H:%M:%S", timeinfo);

        printf("\n--- Ticket ---\n");
        printf("Date & Time: %s\n", date_time);
        printf("Source: %s\n", source_address);
        printf("Destination: %s\n", destination_address);

        if (adult_tickets > 0) {
            printf("Number of Adult Tickets: %d\n", adult_tickets);
            printf("Ticket Price per Adult Ticket: Rupees %.2f\n", ticket_price);
        } else {
            printf("Number of Adult Tickets: 0\n");
        }

        if (child_tickets > 0) {
            printf("Number of Child Tickets: %d\n", child_tickets);
            printf("Ticket Price per Child Ticket: Rupees %.2f\n", child_ticket_price);
        } else {
            printf("Number of Child Tickets: 0\n");
        }

        printf("Total Cost: Rupees %.2f\n", total_cost);
        printf("Type: Unreserved\n");
        printf("----------------\n");

        // Save ticket to file
        FILE *ticket_file = fopen("booked_ticket.txt", "a");
        if (ticket_file == NULL) {
            printf("Error opening file.\n");
            exit(1);
        }

        fprintf(ticket_file, "\n--- Ticket ---\n");
        fprintf(ticket_file, "Date & Time: %s\n", date_time);
        fprintf(ticket_file, "Source: %s\n", source_address);
        fprintf(ticket_file, "Destination: %s\n", destination_address);

        if (adult_tickets > 0) {
            fprintf(ticket_file, "Number of Adult Tickets: %d\n", adult_tickets);
            fprintf(ticket_file, "Ticket Price per Adult Ticket: Rupees %.2f\n", ticket_price);
        } else {
            fprintf(ticket_file, "Number of Adult Tickets: 0\n");
        }

        if (child_tickets > 0) {
            fprintf(ticket_file, "Number of Child Tickets: %d\n", child_tickets);
            fprintf(ticket_file, "Ticket Price per Child Ticket: Rupees %.2f\n", child_ticket_price);
        } else {
            fprintf(ticket_file, "Number of Child Tickets: 0\n");
        }

        fprintf(ticket_file, "Total Cost: Rupees %.2f\n", total_cost);
        fprintf(ticket_file, "Type: Unreserved\n");
        fprintf(ticket_file, "----------------\n");

        fclose(ticket_file);

        printf("\nThank you for booking tickets with us. Have a safe journey!\n");
    }

    return 0;
}
