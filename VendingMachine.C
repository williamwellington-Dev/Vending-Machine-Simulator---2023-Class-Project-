// Pop
// William Wellington
// 2023-11-21
// Purpose: To simulate operation of a pop machine

#include <stdio.h>   // Standard input/output header file
#include <stdlib.h>  // General utilities library. Used for string to int conversion (atoi)
#include <stdbool.h> // For boolean variables


#define FLOOR 30 // Lowest the vending machine can charge
#define CEILING 105 // Highest the vending machine can charge
#define MULTIPLES 5

#define NICKEL 5
#define DIME 10
#define PENTE 20

int refund_coins(int inserted_coins) {
  // Program will return if there are no coins that need to be refunded.
  if (inserted_coins == 0)
    return 0;

  // Program will display the change given
  printf("    Change given: %d centimes as ", inserted_coins);

  // Program will process amount of dimes to dispense
  int number_of_dime = inserted_coins / DIME;
  inserted_coins -= number_of_dime * DIME;

  // Program will process amount of nickels to dispense
  int number_of_nickel = inserted_coins / NICKEL;
  inserted_coins -= number_of_nickel * NICKEL;

  // Display refunded coins
  printf("%d dime(s) and %d nickel(s).\n", number_of_dime, number_of_nickel);

  return 0;
}

int main(int argc, char *argv[]) {

  // Program will close if no price is given
  if (argc <= 1) {
    printf("Please specify the selling price as a command line argument.\nUsage: ./pop [price]\n");
    return 0;
  }

  // Program will convert price to int
  int price = atoi(argv[1]);

  // If cost is not between max and min set cost program will close
  if (price < FLOOR || price > CEILING) {
    printf("Price must be from %d to %d centimes inclusive.\n", FLOOR, CEILING);
    return 0;
  }

  // If cost is not multiples of multiples program will close
  if (price % MULTIPLES != 0) {
    printf("Price must be a multiple of %d.\n", MULTIPLES);
    return 0;
  }

  // main value of pop
  int sum_of_coins = 0;
  bool display_cost = true;
  printf("Welcome to my C Pop Machine!\n");

  // begin program
  while (sum_of_coins < price) {
    if (display_cost) {
      printf("Pop is %d centimes. Please insert any combination of nickels \n[N or n], dimes [D or d] or Pentes [P or p]. You can also \npress R or r for coin return.\n", price);
      display_cost = false;
    }

    printf("Enter coin (NDPR): ");

    char coin;
    bool key_inserted = false;
    scanf(" %c", &coin);
    switch(coin) {
      case 'n':
      case 'N':
        // If insert Nickel
        printf("  Nickel detected.\n");
        sum_of_coins += NICKEL;
        break;
      case 'd':
      case 'D':
        // If insert Dime
        printf("  Dime detected.\n");
        sum_of_coins += DIME;
        break;
      case 'p':
      case 'P':
        // If insert Pente
        printf("  Pente detected.\n");
        sum_of_coins += PENTE;
        break;
      case 'r':
      case 'R':
        // issue Refund
        sum_of_coins = refund_coins(sum_of_coins);
        display_cost = true;
        break;
      case 'k':
      case 'K':
        // insert Key
        key_inserted = true;
        break;
      default:
        // input is Unknown
        printf("  Unknown coin rejected.\n");
        break;
    }

    // Key insert
    if (key_inserted) {
      refund_coins(sum_of_coins);
      break;
    }

    // Program calculating sum
    int remaining_price = price - sum_of_coins;
    printf("    You have inserted a total of %d centimes.\n", sum_of_coins);

    if (remaining_price > 0) { // If not enough coin is inserted
      printf("    Please insert %d more centimes.\n", remaining_price);
    } else { // If enough coin is inserted
      printf("    Pop is dispensed. Thank you for your business! Please come again.\n");
      sum_of_coins -= price;
      sum_of_coins = refund_coins(sum_of_coins);
      display_cost = true;
    }
  }

  printf("Shutting down. Goodbye.\n");
  return 0;
}