# Vending Machine Simulator

A command-line vending machine simulator written in C, originally built as a 2023 class project. You set the price of a pop when you start the program, insert coins one at a time, and the machine dispenses the pop and returns your change.

Prices are in **centimes**, and the machine accepts three coins:

| Key | Coin | Value |
|-----|------|-------|
| `N` / `n` | Nickel | 5 centimes |
| `D` / `d` | Dime | 10 centimes |
| `P` / `p` | Pente | 20 centimes |

## Features

- **Price validation:** the price must be between 30 and 105 centimes and a multiple of 5.
- **Running total:** after every coin, the machine shows how much has been inserted and how much is still owed.
- **Change calculation:** overpayments are returned using as many dimes as possible, then nickels.
- **Coin return:** press `R` / `r` at any time to get your coins back.
- **Service key:** press `K` / `k` to refund any inserted coins and shut the machine down.
- **Bad input handling:** any other key is rejected as an unknown coin.

## How to Run

Compile with GCC:

```bash
gcc -o pop pop.c
```

Run it with the price as a command-line argument:

```bash
./pop 30
```

## Example

```
$ ./pop 30
Welcome to my C Pop Machine!
Pop is 30 centimes. Please insert any combination of nickels
[N or n], dimes [D or d] or Pentes [P or p]. You can also
press R or r for coin return.
Enter coin (NDPR): p
  Pente detected.
    You have inserted a total of 20 centimes.
    Please insert 10 more centimes.
Enter coin (NDPR): p
  Pente detected.
    You have inserted a total of 40 centimes.
    Pop is dispensed. Thank you for your business! Please come again.
    Change given: 10 centimes as 1 dime(s) and 0 nickel(s).
Pop is 30 centimes. Please insert any combination of nickels
[N or n], dimes [D or d] or Pentes [P or p]. You can also
press R or r for coin return.
Enter coin (NDPR): k
Shutting down. Goodbye.
```

## Concepts Used

- Command-line arguments (`argc` / `argv`) and string-to-integer conversion with `atoi`
- Input validation
- A `while` loop with a `switch` statement to handle user input
- Constants defined with `#define`
- A helper function for calculating change

## Author

William Wellington
