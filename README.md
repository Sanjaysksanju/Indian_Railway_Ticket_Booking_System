---

# Ticket Booking System

## Overview

Welcome to the **Ticket Booking System**! This console-based application is designed to simplify the process of booking tickets for travel. It allows users to select sources and destinations, book tickets, and handle payments with ease.

![image](https://github.com/user-attachments/assets/46570d7d-1507-494e-99b3-86519004be8b)


## Features

- **Route Selection**: Choose your starting point and destination from a predefined list.
- **Ticket Booking**: Book tickets for adults and children, with different pricing.
- **Payment Options**: Supports Credit/Debit Card, PayPal, and UPI payments.
- **Ticket Generation**: Generate and save a detailed ticket with booking information.

## Screenshots

Here are some screenshots of the application in action:

1. **Source Selection**
   ![Source Selection](path/to/source_selection.png)  <!-- Replace with an actual screenshot -->

2. **Payment Method Selection**
   ![Payment Method](path/to/payment_method.png)  <!-- Replace with an actual screenshot -->

3. **Generated Ticket**
   ![Generated Ticket](path/to/generated_ticket.png)  <!-- Replace with an actual screenshot -->

## Files

- **`main.c`**: The main file that controls the flow of the application.
- **`input_handling.c`**: Contains functions for user input handling.
- **`payment_handling.c`**: Contains functions for payment processing.
- **`route_handling.c`**: Handles route display and pricing.
- **`input_handling.h`**: Header file for input handling functions.
- **`payment_handling.h`**: Header file for payment handling functions.
- **`route_handling.h`**: Header file for route handling functions.
- **`Kengeri.txt`**, **`Ramanagara.txt`**, **`Channapatana.txt`**, **`Maddur.txt`**, **`Mandya.txt`**: Text files with route and pricing information.

## Getting Started

### Prerequisites

- **GCC Compiler**: Ensure you have GCC or a compatible C compiler installed.
- **Text Files**: Place the route information text files in the same directory as the executable.

### Installation

1. **Clone the Repository**

   ```bash
   git clone  https://github.com/Sanjaysksanju/Sanjay-S-K-Project-etechprowess.git
   ```

2. **Navigate to the Project Directory**

   ```bash
   cd ticket-booking-system
   ```

3. **Compile the Program**

   ```bash
   gcc main.c input_handling.c payment_handling.c route_handling.c -o ticket_booking_system
   ```

### Running the Application

- **On Unix-like Systems**:

   ```bash
   ./ticket_booking_system
   ```

- **On Windows PowerShell**:

   ```powershell
   .\ticket_booking_system.exe
   ```

## Usage

1. **Select Source**: Choose your departure point from the list.
2. **Select Destination**: Pick your destination from available options.
3. **Enter Ticket Information**: Specify the number of adult and child tickets.
4. **Choose Payment Method**: Select your preferred payment method (Credit/Debit Card, PayPal, or UPI).
5. **Confirm Booking**: Review your booking details and complete the transaction. A ticket will be generated and saved.

## Error Handling

- Ensure all necessary text files are in the same directory as the executable.
- Follow prompts carefully to avoid input errors.

## Contributing

Contributions are welcome! If you have suggestions or improvements, please submit an issue or pull request.

## Contact

For questions or support, please reach out to [aksha9538@gmail.com](mailto:aksha9538@gmail.com).

---


