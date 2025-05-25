******************************

A simple console-based to-do list application for diving into the C programming language.

******************************

Requirements for a simple console-based to-do list application:
Functional Requirements

    Add Task:
        The user should be able to add a new task to the to-do list.
        Each task should have a title and an optional description.

    View Tasks:
        The user should be able to view all tasks in the to-do list.
        Each task should display its title, description (if any), and a unique identifier (e.g., task number).

    Delete Task:
        The user should be able to delete a task from the list using its unique identifier.
        The application should confirm the deletion before proceeding.

    Mark Task as Complete:
        The user should be able to mark a task as complete.
        Completed tasks should be visually distinguishable (e.g., by using a different symbol or strikethrough).

    Save and Load Tasks:
        The application should save the current list of tasks to a file when the user exits.
        Upon starting the application, it should load the tasks from the file if it exists.

Non-Functional Requirements

    User Interface:
        The application should have a simple and clear text-based user interface.
        It should provide clear instructions for each action.

    Error Handling:
        The application should handle invalid inputs gracefully (e.g., when trying to delete a non-existent task).
        It should provide appropriate error messages to the user.

    Data Persistence:
        The tasks should persist between sessions, meaning they should be saved to a file and loaded when the application starts.

    Performance:
        The application should be responsive and handle a reasonable number of tasks without noticeable delay.

    Extensibility:
        The design should allow for future enhancements, such as adding due dates, priorities, or categories for tasks.

