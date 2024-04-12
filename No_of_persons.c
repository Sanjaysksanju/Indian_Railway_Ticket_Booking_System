#include <stdio.h>

// Function to get the number of persons booking tickets
int getNumberOfPersons() {
    int numPersons;
    printf("How many persons are booking tickets? ");
    scanf("%d", &numPersons);
    return numPersons;
}
