#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Some stored users in the system to make it a bit more interactive
 * I will be creating 5 user array structs and an id
 * all for verificaion
 */
#define NUM_USERS 5
// struct section
struct User {
  int id;
  char name[20];
};

struct User Users[NUM_USERS] = {
    {1, "John"}, {2, "Frank"}, {3, "Micheal"}, {4, "Elvis"}, {5, "David"}};
// Struct section END

// declaring my functions
int login(int id, char *name);
void BalanceCheck(float balance);
float DepositMoney();
float WithdrawMoney();
void MainMenu();

// MAIN FUNCTION SECTION
int main() {

  // some local declarations

  int option;
  float balance;
  int choose;
  bool again = true;

  system("clear");
  // END OF IT

  while (again) {
    MainMenu();

    printf("\t\t\t\t\t\t\t>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<\n");
  }
}
// MAIN FUNCTION END

// DEFINING MY FUNCTIONS

// THE LOGIN FUNCTION
int login(int id, char *name) {
  int i;
  for (i = 0; i < NUM_USERS; i++) {
    if (Users[i].id == id && strcmp(Users[i].name, name) == 0) {
      return 1; // login successful
    }
  }
  return 0; // login failed
}
// THE LOGIN FUNCTION END

// THE MAINMENU FUNCTION

void MainMenu() {
  printf("\t\t\t\t\t\t******************Hello!*******************\n");
  printf("\t\t\t\t\t\t**********Welcome to Beta Banking**********\n\n");
  printf("\t\t\t\t\t\t\t****Select an options below****\n\n");
  printf("\t\t\t\t\t\t< 1 >  Check Balance\n");
  printf("\t\t\t\t\t\t< 2 >  Deposit\n");
  printf("\t\t\t\t\t\t< 3 >  Withdraw\n");
  printf("\t\t\t\t\t\t< 4 >  Exit\n\n");
}
// THE END OF THE MAINMENU FUNCTION
