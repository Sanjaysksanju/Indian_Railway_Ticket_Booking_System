#ifndef ROUTE_HANDLING_H
#define ROUTE_HANDLING_H

void display_routes(const char *filename);
int get_ticket_price(const char *filename, int destination, float *ticket_price, float *child_ticket_price, char *destination_address);

#endif // ROUTE_HANDLING_H
