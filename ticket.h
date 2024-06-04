#ifndef MAIN_H_INCLUDED // Header guard to prevent multiple inclusions
#define MAIN_H_INCLUDED // Define to mark the start of the header file

#include<stdio.h> // Including standard input-output header file

// Function prototypes for functions used in main.c
void displayDestinations(); // Function to display available destinations
int calculateTotalCost(int numTickets, int ticketPrice); // Function to calculate total cost of tickets
int validatePIN(int pin); // Function to validate PIN
void processPayment(int totalCost); // Function to process payment

#endif // End of header file
