#include <stdbool.h>
#include <stdio.h>

bool active = true;

void promtSelection(int selection) {
  switch (selection) {
  case 1:
    printf("You've selected 1.\n");
    break;
  case 2:
    printf("You've selected 2.\n");
    break;
  case 3:
    active = false;
    break;
  default:
    printf("Invalid option.\n");
  }
}

void displayMenu() {
  int selection;
  printf("1. Add task\n2. List tasks\n3. Exit program\n");
  scanf("%d", &selection);
  while (getchar() != '\n');
  promtSelection(selection);
}

int main(void) {
  while (active) displayMenu();
  return 0;
}