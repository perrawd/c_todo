#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool active = true;
int listItem = 0;

struct Task { const int ID; char title[50]; char description[50]; bool completed;};
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

char* getInputText(char* descriptionType) {
  static char inputText[50];
  printf("Enter task %s: ", descriptionType);
  fgets(inputText, sizeof(inputText), stdin);
  inputText[strcspn(inputText, "\n")] = 0;
  return inputText;
}

void addTask() {
  struct Task newTask = { .ID = listItem + 1, .completed = false };
  strcpy(newTask.title, getInputText("title"));
  strcpy(newTask.description, getInputText("description"));
  memcpy(&listOfTasks[listItem], &newTask, sizeof(struct Task));
  listItem++;
  return;
}

void displayListOfTask() {
  int i;
  for (i = 0; i < listItem; i++) {
    printf("Task ID: %d\n", listOfTasks[i].ID);
    printf("Task title: %s\n", listOfTasks[i].title);
    printf("Task description: %s\n", listOfTasks[i].description);
    printf("Completed: %s\n", listOfTasks[i].completed ? "Yes" : "No");
    printf("************************\n");
  }
  return;
}