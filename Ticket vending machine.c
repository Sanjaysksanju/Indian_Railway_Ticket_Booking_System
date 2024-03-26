#include<stdio.h>

int main() {
    int MenuOption; // initializing Variable for selecting option;

    do {
        // Choose option 1-5 for selecting destination address.
        printf("Here are the list of destination places\n1) Ramanagara\n2) Maddur\n3) Mandya\n4) Mysuru\n5) Exit\nEnter your option: ");
        scanf("%d", &MenuOption);

        // here I use switch case for selecting location for generating tickets
        switch (MenuOption) {
            // if case 1 selected ticket booked to Ramanagara etc follows same
            case 1:
                printf("Ramanagara\n");
                printf("Ticket Booked Successfully\nHappy Journey! ");
                break;
            case 2:
                printf("Maddur ");
                printf("Ticket Booked Successfully\nHappy Journey!");
                break;
            case 3:
                printf("Mandya ");
                printf("Ticket Booked Successfully\nHappy Journey!");
                break;
            case 4:
                printf("Mysuru ");
                printf("Ticket Booked Successfully\nHappy Journey!");
                break;
            case 5:
                printf("Happy journey\n");
                return 0; // Exit the program
            // In case if you choose option 6 it shows invalid option
            case 6:
                printf("Invalid option\n");
                printf("Enter Valid option\n");
                printf("Ticket Booking Failed\n");
                break;
            default:
                printf("Invalid option\n");
                printf("Enter a valid option\n");
                printf("Ticket Booking Failed\n");
        }
    } while (MenuOption < 1 || MenuOption > 5); // Loop until a valid option is entered

    return 0;
}
