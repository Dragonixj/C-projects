#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define MAX_PIN_LENGTH 4

// User  structure
typedef struct {
  char name[50];
  char pin[MAX_PIN_LENGTH + 1]; // +1 for  a null terminator
  long long accNum;
  float balance;
} User;

// global variables
User users[MAX_USERS];
int numUsers = 0;
int currentUserIndex = -1;

// Functions
void login();
void MainMenu();
void checkBalance();
void MoneyDeposit();
void WithdrawMoney();
void ExitMenu();
void errorMessage();
void UpdateUserDetails();

// Main Code
int main() {
  // Local Declarations

  int again = 1;

  // Read User data from file

  FILE *fp = fopen("User.dat", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error! Cannot open the user.dat file\n");
    exit(1);
  }

  while (fscanf(fp, "%s %s %lld %f", users[numUsers].name, users[numUsers].pin,
                &users[numUsers].accNum, &users[numUsers].balance) != EOF) {

#ifdef DEBUG
    printf("%s | %s | %lld | %2f\n", users[numUsers].name, users[numUsers].pin,
           users[numUsers].accNum, users[numUsers].balance);
#endif
    numUsers++;
  }
  fclose(fp);
  // user dat file side end

  // perform login
  login();
  //
  while (1) {
    MainMenu();

    int option;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Your Selection:\t");
    scanf("%d", &option);

    switch (option) {
    case 1:
      system("clear");
      checkBalance();
      break;
    case 2:
      system("clear");
      MoneyDeposit();
      break;
    case 3:
      system("clear");
      WithdrawMoney();
      break;
    case 4:
      system("clear");
      ExitMenu();
      return 0;
    default:
      errorMessage();
      break;
    }
  }

  return 0;
} // main code

// Functions

// Main Menu
void MainMenu() {

  printf("******************Hello!*******************\n");
  printf("**********Welcome to HEF ATM Banking***********\n\n");
  printf("****Please choose one of the options below****\n\n");
  printf("< 1 >  Check Balance\n");
  printf("< 2 >  Deposit\n");
  printf("< 3 >  Withdraw\n");
  printf("< 4 >  Exit\n\n");
}
// Check Balance

void checkBalance() {
  printf("You Choose to See your Balance\n");
  printf("\n\n****Your Available Balance is: $%.2f\n\n",
         users[currentUserIndex].balance);
}
// Deposit Money

void MoneyDeposit() {
  printf("You choose to Deposit a money\n");
  printf("$$$$Your Balance is: $%.2f\n\n", users[currentUserIndex].balance);

  float deposit;
  printf("****Enter your amount to Deposit: \n");
  scanf("%f", &deposit);

  users[currentUserIndex].balance += deposit;
  printf("\n****Your New Balance is:   $%.2f\n\n",
         users[currentUserIndex].balance);
}

// Withdraw Money
void WithdrawMoney() {

  float withdraw;
  char pin[5];
  int back = 1;

  printf("You choose to Withdraw a money\n");
  printf("$$$$Your Balance is: $%.2f\n\n", users[currentUserIndex].balance);

  // Pin verification
  printf("Enter your Pin");
  scanf("%s", pin);

  if (strcmp(pin, users[currentUserIndex].pin) != 0) {
    printf("Invalid Pin");
    return;
  }

  while (back) {
    printf("Enter Amount to withdraw");
    scanf("%f", &withdraw);

    if (withdraw > users[currentUserIndex].balance) {
      printf("Insufficient Balance, Please input a different Amount\n");
      continue;
    }

    users[currentUserIndex].balance -= withdraw;
    UpdateUserDetails(); // updates user data in the the database

    printf("\n$$$Your withdrawing amount is: $%.2f\n", withdraw);
    printf("**** Your new Balance is:  $%.2f\n\n",
           users[currentUserIndex].balance);
  }
}

// Exit Menu
void ExitMenu() {
  printf("--------------Take your receipt!!!------------------\n");
  printf("-----Thank you for using HEF BANKING ATM !!!-----\n");

} // exit menu
  // login function
void login() {
  printf("Enter your PIN to login: \n");
  char pin[MAX_PIN_LENGTH + 1];
  scanf("%s", pin);

  for (int i = 0; i < numUsers; i++) {
    if (strcmp(pin, users[i].pin) == 0) {
      currentUserIndex = i;
      printf("Welcome, %s!n", users[i].name);
      return;
    }
  }
  printf("Error: Invalid PIN\n");
  exit(1);
}
// Login function
//  Error Message
void errorMessage() {
  ;
  printf("+++!!!You selected invalid number!!!+++\n");
}

void UpdateUserDetails() {
  printf("\n**** Update Personal Information ****\n");

  printf("Enter your new name: ");
  scanf("%s", users[currentUserIndex].name);

  printf("Enter your PIN:  ");
  scanf("%s", users[currentUserIndex].pin);

  printf("\n**** Personal Information Updated Successfully! ****\n");
}
