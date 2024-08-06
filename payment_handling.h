#ifndef PAYMENT_HANDLING_H
#define PAYMENT_HANDLING_H

void handle_payment(int payment_method, float total_cost, char *card_number, char *card_expiry, char *card_cvv, char *paypal_email, char *upi_id, int *pin);

#endif // PAYMENT_HANDLING_H
