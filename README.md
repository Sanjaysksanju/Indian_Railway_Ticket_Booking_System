# Ticket Booking System
This is a simple command-line ticket booking system written in C. It allows users to select a destination, specify the number of persons booking tickets, and choose a payment method to complete the booking process.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
## Introduction
This project provides a user-friendly interface for booking tickets to different destinations. With just a few simple steps, users can select their desired destination, specify the number of persons booking tickets, and choose a convenient payment method to complete the booking process.
## Features
- Displays a list of destination places.
- Allows the user to select a destination.
- Prompts the user to enter the number of persons booking tickets.
- Validates the number of persons entered.
- Calculates the total cost of the tickets based on the selected destination.
- Offers three payment options: UPI Payment, Card Payment, and Cash Payment.
- For UPI Payment:
  - Allows the user to choose between scanning a QR code and entering a UPI ID.
  - Prompts the user for UPI details accordingly.
- For Card Payment:
  - Asks the user to enter their card number and PIN.
- For Cash Payment:
  - Proceeds with the booking without further input.
- Books the tickets and displays the details including the payment method, payment details, total cost, and a success message.

  ## Separate.c file functionalities brief view.
- **Destination Selection**: Choose from a list of available destinations including Ramanagara, Maddur, Mandya, and Mysuru.
- **Ticket Booking**: Specify the number of persons booking tickets.
- **Payment Options**: Select from multiple payment methods including UPI Payment, Card Payment, and Cash Payment.
- **Flexible and Easy to Use**: Simple command-line interface makes it easy for users to navigate and book tickets quickly.
- **Customizable**: Easily adaptable to add more destinations or payment methods as needed.
