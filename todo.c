#include <stdbool.h>
#include <stdio.h>

bool active = true;

void displayMenu(bool *active) {
  int selection;

  printf("1. Add task\n2. List tasks\n3. Exit program\n");
  scanf("%d", &selection);
  while (getchar() != '\n');

  switch (selection) {
    case 1:
      printf("You've selected 1.\n");
      break;
    case 2:
      printf("You've selected 2.\n");
      break;
    case 3:
      *active = false;
      break;
    default:
      printf("Invalid option.\n");
  }
}

int main(void) {
  while (active) displayMenu(&active);
  return 0;
}