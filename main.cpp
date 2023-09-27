// A vector to store the tasks
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// A struct to represent a task with a name and a status
struct Task {
    string name;
    string status;
};

// A vector to store the tasks
vector<Task> tasks;

// A function to add a task to the vector
void add_task() {
    // Ask the user to input a task
    cout << "Enter a task: ";
    string task;
    getline(cin, task);
    // Create a Task object with the input name and a pending status
    Task t;
    t.name = task;
    t.status = "pending";
    // Push the Task object to the vector
    tasks.push_back(t);
    // Print a confirmation message
    cout << "Task added successfully.\n";
}

// A function to display the tasks in the vector
void view_tasks() {
    // Check if the vector is empty
    if (tasks.empty()) {
        // Print a message that there are no tasks
        cout << "You have no tasks.\n";
    } else {
        // Print a header for the tasks
        cout << "Your tasks are:\n";
        // Loop through the vector and print each task with its status
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].name << " (" << tasks[i].status << ")\n";
        }
    }
}

// A function to mark a task as completed
void mark_task() {
    // Ask the user to enter the number of the task they want to mark as completed
    cout << "Enter the number of the task you want to mark as completed: ";
    int num;
    cin >> num;
    // Check if the number is valid
    if (num < 1 || num > tasks.size()) {
        // Print an error message
        cout << "Invalid number.\n";
    } else {
        // Change the status of the task to completed
        tasks[num - 1].status = "completed";
        // Print a confirmation message
        cout << "Task marked as completed.\n";
    }
}

// A function to remove a task from the vector
void remove_task() {
    // Ask the user to enter the number of the task they want to remove
    cout << "Enter the number of the task you want to remove: ";
    int num;
    cin >> num;
    // Check if the number is valid
    if (num < 1 || num > tasks.size()) {
        // Print an error message
        cout << "Invalid number.\n";
    } else {
        // Erase the task from the vector
        tasks.erase(tasks.begin() + num - 1);
        // Print a confirmation message
        cout << "Task removed successfully.\n";
    }
}

// A function to display the menu and handle user choices
void menu() {
    // Print a welcome message
    cout << "Welcome to your simple console-based to-do list manager.\n";
    // Declare a variable to store the user choice
    int choice;
    // Use a do-while loop to repeat until the user chooses to exit
    do {
        // Print the menu options
        cout << "\nPlease choose an option:\n";
        cout << "1. Add a task\n";
        cout << "2. View tasks\n";
        cout << "3. Mark a task as completed\n";
        cout << "4. Remove a task\n";
        cout << "5. Exit\n";
        // Ask the user to enter their choice
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after cin
        // Use a switch statement to handle different choices
        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                mark_task();
                break;
            case 4:
                remove_task();
                break;
            case 5:
                cout << "Thank you for using this program. Goodbye.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5); // Repeat until the user chooses to exit
}

// The main function that runs the program
int main() {
    menu();
}
