#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "route_handling.h"

// Function to display routes from a file
void display_routes(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[100];
    int line_num = 1;
    while (fgets(line, sizeof(line), file)) {
        printf("%d. %s", line_num++, line);
    }
    printf("%d. Exit\n", line_num);

    fclose(file);
}

// Function to get ticket price
int get_ticket_price(const char *filename, int destination, float *ticket_price, float *child_ticket_price, char *destination_address) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    char line[100];
    int line_num = 1;
    while (fgets(line, sizeof(line), file)) {
        if (line_num == destination) {
            char *price_str = strstr(line, ": ");
            if (price_str) {
                *ticket_price = atof(price_str + 2);
                *child_ticket_price = *ticket_price / 2; // Half price for child tickets
                strtok(line, ":");
                strcpy(destination_address, line);
                fclose(file);
                return 1; // Valid destination
            }
        }
        line_num++;
    }

    fclose(file);
    return 0; // Invalid destination
}
