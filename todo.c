#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool active = true;
int listItem = 0;

struct Task {
  char title[50];
  char description[50];
};
struct Task listOfTasks[10] = {
    {"", ""}
};

void displayListOfTask() {
    int i;
    for (i = 0; i < 10; i++) {
      printf("Task title: %s\n", listOfTasks[i].title);
      printf("Task description: %s\n", listOfTasks[i].description);
      printf("************************\n");
    }
    return;
}

void addTask() {
  int listItemIndex = listItem;
  printf("Enter task title: ");
  fgets(listOfTasks[listItemIndex].title, sizeof(listOfTasks[0].title), stdin);
  // Remove the newline character if present
  listOfTasks[listItemIndex].title[strlen(listOfTasks[listItemIndex].title) - 1] = '\0';
  listItem += 1;
  return;
}

void promptSelection(int selection) {
  switch (selection) {
    case 1:
      addTask();
      break;
    case 2:
      displayListOfTask();
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
  promptSelection(selection);
}

int main(void) {
  while (active) displayMenu();
  return 0;
}