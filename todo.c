#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* file;

bool active = true;
int amountOfTasks = 0;

struct Task { const int ID; char title[50]; char description[50]; bool completed;};
struct Task *listOfTasks = NULL;

#define CLEAR_SCREEN printf("\e[1;1H\e[2J");

int loadFile();
void setListOfTasks();
void displayMenu();
void promptSelection(int selection);
void addTask();
char* getInputText(char* descriptionType);
void displayListOfTask();
void editTask();
int getTaskIndex();
void promptForTaskIndex(int *taskIndex);
int getEditType();
void promptForEditType(int *editType);
void processEdit(int taskIndex, int editType);
void deleteTask(int taskIndex);

int main(void) {
  if (loadFile() == 1) return 1;
  setListOfTasks();
  while (active) displayMenu();
  fclose(file);
  return 0;
}

int loadFile() {
  file =  fopen("todos.txt", "w");
  if (file == NULL) {
    perror("Error creating file");
    return 1;
  }
  return 0;
}

void setListOfTasks() {
  listOfTasks = (struct Task*)malloc(5 * sizeof(struct Task));
  if (listOfTasks == NULL) {
    printf("Memory not allocated.\n");
    exit(1);
  }
}

void displayMenu() {
  CLEAR_SCREEN;
  int selection;
  printf("1. Add task\n2. List tasks\n3. Edit task\n4. Exit program\n");
  scanf("%d", &selection);
  while (getchar() != '\n');
  promptSelection(selection);
}

void promptSelection(int selection) {
  switch (selection) {
    case 1: addTask(); break;
    case 2: displayListOfTask(); break;
    case 3: editTask(); break;
    case 4: active = false; break;
    default: printf("Invalid option.\n");
  }
}

void addTask() {
  CLEAR_SCREEN;
  struct Task newTask = { .ID = amountOfTasks + 1, .completed = false };
  strcpy(newTask.title, getInputText("title"));
  strcpy(newTask.description, getInputText("description"));
  memcpy(&listOfTasks[amountOfTasks], &newTask, sizeof(struct Task));
  amountOfTasks++;
  return;
}

char* getInputText(char* descriptionType) {
  CLEAR_SCREEN;
  static char inputText[50];
  printf("Enter task %s: ", descriptionType);
  fgets(inputText, sizeof(inputText), stdin);
  inputText[strcspn(inputText, "\n")] = 0;
  return inputText;
}

void displayListOfTask() {
  CLEAR_SCREEN;
  for (int i = 0; i < amountOfTasks; i++) {
    printf("Task index: %d\n", i + 1);
    printf("Task title: %s\n", listOfTasks[i].title);
    printf("Task description: %s\n", listOfTasks[i].description);
    printf("Completed: %s\n", listOfTasks[i].completed ? "Yes" : "No");
    printf("************************\n");
  }
  printf("Press ENTER to exit view");
  getchar();
  return;
}


void editTask() {
  int taskIndex = getTaskIndex();
  int editType = getEditType();
  processEdit(taskIndex, editType);
}

int getTaskIndex() {
  int taskIndex = 0;
  promptForTaskIndex(&taskIndex);
  return taskIndex - 1;
}

void promptForTaskIndex(int *taskIndex) {
  while (*taskIndex == 0) {
    CLEAR_SCREEN;
    printf("(Enter 0 for list of tasks)\nEnter the index of the task you want to edit: ");
    scanf("%d", taskIndex);
    while (getchar() != '\n');
    if (*taskIndex == 0) displayListOfTask();
  }
}

int getEditType() {
  int editType;
  promptForEditType(&editType);
  return editType;
}

void promptForEditType(int *editType) {
  CLEAR_SCREEN;
  printf("1. Mark task as completed\n2. Edit task title\n3. Edit task description\n4. Delete task\n5. Cancel\n");
  scanf("%d", editType);
  while (getchar() != '\n');
}

void processEdit(int taskIndex, int editType) {
  switch(editType) {
    case 1: listOfTasks[taskIndex].completed = true; break;
    case 2: memcpy(&listOfTasks[taskIndex].title, getInputText("title"), sizeof(listOfTasks[taskIndex].title)); break;
    case 3: memcpy(&listOfTasks[taskIndex].description, getInputText("description"), sizeof(listOfTasks[taskIndex].description)); break;
    case 4: deleteTask(taskIndex);
    default: return;
  }
}

void deleteTask(int taskIndex) {
  for (int i = taskIndex; i < (amountOfTasks - 1); i++) {
     memcpy(&listOfTasks[i], &listOfTasks[i + 1], sizeof(struct Task));
  };
  amountOfTasks--;
}
