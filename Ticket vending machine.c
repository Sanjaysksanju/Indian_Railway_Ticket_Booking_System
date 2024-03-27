#include <stdio.h>

int main() {
    int MenuOption; // initializing Variable for selecting option;
    int numPersons; // Variable to store the number of persons

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
        printf("How many persons are booking tickets? ");
        scanf("%d", &numPersons);

        // Validate the number of persons
        if (numPersons <= 0) {
            printf("Invalid number of persons. Please enter a valid number.\n");
            continue;
        }

        // here I use switch case for selecting location for generating tickets
        switch (MenuOption) {
            // if case 1 selected ticket booked to Ramanagara etc follows same
            case 1:
                printf("%d ticket(s) booked to Ramanagara\n", numPersons);
                printf("Ticket(s) Booked Successfully\nHappy Journey! ");
                break;
            case 2:
                printf("%d ticket(s) booked to Maddur\n", numPersons);
                printf("Ticket(s) Booked Successfully\nHappy Journey!");
                break;
            case 3:
                printf("%d ticket(s) booked to Mandya\n", numPersons);
                printf("Ticket(s) Booked Successfully\nHappy Journey!");
                break;
            case 4:
                printf("%d ticket(s) booked to Mysuru\n", numPersons);
                printf("Ticket(s) Booked Successfully\nHappy Journey!");
                break;
        }

    } while (MenuOption != 5); // Loop until the user chooses to exit

    return 0;
}
