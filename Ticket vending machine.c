#include<stdio.h>
int main()
{
    int MenuOption ; // initializing Variable for selecting option;
    do{

    printf(" 1)Ramanagara\n 2)Maddur\n 3)Mandya\n 4)Mysuru\n 5)exit\n enter your option: ");//choose option 1 to 6;
    scanf("%d",&MenuOption);

    //here i use switch case for selecting location for generating tickets;
    switch(MenuOption){

    // if case 1 selected ticket booked to Ramanagara follows same ;
    case 1:
        printf("Ramanagara\n");
        printf("Ticket Booked Successfully\n");
        break;
    case 2:
        printf("Maddur");
         printf("Ticket Booked Successfully\n");
        break;
    case 3:
        printf("Mandya");
         printf("Ticket Booked Successfully\n");
        break;
    case 4:
        printf("Mysuru");
         printf("Ticket Booked Successfully\n");
        break;
     case 5:
        printf("Exiting program\n");
        return 0; // Exit the program
     //In case if you choose option 6 it shows invalid option;
    case 6:
        printf("invalid option\n");
        printf("Enter Valid option\n");
        printf("Ticket Booking Failed\n");
        break;

       default:
                printf("Invalid option\n");
                printf("Enter a valid option\n");
                printf("Ticket Booking Failed\n");
        }
    } while (MenuOption < 1 || MenuOption > 4); // Loop until a valid option is entered

    return 0;
}

