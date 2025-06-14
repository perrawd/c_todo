#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool active = true;
int amountOfTasks = 0;

struct Task { const int ID; char title[50]; char description[50]; bool completed;};
struct Task *listOfTasks = NULL;

void setListOfTasks();
void displayMenu();
void promptSelection(int selection);
void addTask();
void editTask();
char* getInputText(char* descriptionType);
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
  printf("1. Add task\n2. List tasks\n3. Edit task\n4. Exit program\n");
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
      editTask();
      break;
    case 4:
      active = false;
      break;
    default:
      printf("Invalid option.\n");
  }
}

void addTask() {
  struct Task newTask = { .ID = amountOfTasks + 1, .completed = false };
  strcpy(newTask.title, getInputText("title"));
  strcpy(newTask.description, getInputText("description"));
  memcpy(&listOfTasks[amountOfTasks], &newTask, sizeof(struct Task));
  amountOfTasks++;
  return;
}

void editTask() {
  printf("(Enter 0 for list of tasks)\n");
  printf("Enter the index of the task you want to edit: ");
  int taskIndex;
  scanf("%d", &taskIndex); taskIndex -= 1;
  while (getchar() != '\n');

  int selection;
  printf("1. Mark task as completed\n2. Edit task title\n3. Edit task description\n4. Cancel\n");
  scanf("%d", &selection);
  while (getchar() != '\n');
  
  switch(selection) {
    case 1: listOfTasks[taskIndex].completed = true; break;
    case 2: memcpy(&listOfTasks[taskIndex].title, getInputText("title"), sizeof(listOfTasks[taskIndex].title)); break;
    case 3: memcpy(&listOfTasks[taskIndex].description, getInputText("description"), sizeof(listOfTasks[taskIndex].description)); break;
    default: return;
  }
}

char* getInputText(char* descriptionType) {
  static char inputText[50];
  printf("Enter task %s: ", descriptionType);
  fgets(inputText, sizeof(inputText), stdin);
  inputText[strcspn(inputText, "\n")] = 0;
  return inputText;
}

void displayListOfTask() {
  int i;
  for (i = 0; i < amountOfTasks; i++) {
    printf("Task index: %d\n", i + 1);
    printf("Task title: %s\n", listOfTasks[i].title);
    printf("Task description: %s\n", listOfTasks[i].description);
    printf("Completed: %s\n", listOfTasks[i].completed ? "Yes" : "No");
    printf("************************\n");
  }
  return;
}