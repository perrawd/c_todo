#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool active = true;
int listItem = 0;

struct Task { int id; char title[50]; char description[50]; bool completed;};
struct Task *listOfTasks = NULL;

void setListOfTasks();
void displayMenu();
void promptSelection(int selection);
void addTask();
void displayListOfTask();

int main(void) {
  setListOfTasks();
  while (active) displayMenu();
  return 0;
}

void setListOfTasks() {
  listOfTasks = (struct Task*)malloc(5 * sizeof(struct Task));
  printf("Memory allocated.\n");
  if (listOfTasks == NULL) {
    printf("Memory not allocated.\n");
    exit(1);
  }
}

void displayMenu() {
  int selection;
  printf("1. Add task\n2. List tasks\n3. Exit program\n");
  scanf("%d", &selection);
  while (getchar() != '\n');
  promptSelection(selection);
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

void addTask() {
  int listItemIndex = listItem;
  printf("Enter task title: ");
  fgets(listOfTasks[listItemIndex].title, sizeof(listOfTasks[0].title), stdin);
  // Remove the newline character if present
  listOfTasks[listItemIndex].title[strlen(listOfTasks[listItemIndex].title) - 1] = '\0';
  listOfTasks[listItemIndex].id = listItem + 1;
  listItem += 1;
  return;
}

void displayListOfTask() {
  int i;
  for (i = 0; i < listItem; i++) {
    printf("Task ID: %d\n", listOfTasks[i].id);
    printf("Task title: %s\n", listOfTasks[i].title);
    printf("Task description: %s\n", listOfTasks[i].description);
    printf("Completed: %s\n", listOfTasks[i].completed ? "Yes" : "No");
    printf("************************\n");
  }
  return;
}