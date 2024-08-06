---

# Ticket Booking System

## Overview

<div style="font-size: 1.2em;">
Welcome to the <strong>Ticket Booking System</strong>! This console-based application is designed to simplify the process of booking tickets for travel. It allows users to select sources and destinations, book tickets, and handle payments with ease.
</div>


![image](https://github.com/user-attachments/assets/1e19c36f-3301-425c-9a39-8b30848a1d64)


## Features

- **Route Selection**: Choose your starting point and destination from a predefined list.
- **Ticket Booking**: Book tickets for adults and children, with different pricing.
- **Payment Options**: Supports Credit/Debit Card, PayPal, and UPI payments.
- **Ticket Generation**: Generate and save a detailed ticket with booking information.

## Screenshots

Here are some screenshots of the application in action:

1. **Source Selection**

   ![Source Selection](https://github.com/user-attachments/assets/8d5e99a0-83c5-40ae-a72a-ea43519bd3ff)

2. **Destination Selection**
   
   ![Destination Selection](https://github.com/user-attachments/assets/d685aca6-f5d2-4af5-924e-794f3da22511)

3. **Payment Method Selection**
   
   ![Payment Method](https://github.com/user-attachments/assets/3e5b7359-b1d9-4c16-ad60-1699267f3f64)

4. **Generated Ticket**
   
  ![Generated Ticket](https://github.com/user-attachments/assets/12bc410c-c79a-4872-94f2-35bc5b68d241)

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
   git clone https://github.com/Sanjaysksanju/Sanjay-S-K-Project-etechprowess.git
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

