#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    Task(const string & description) : description(description), completed(false) {}
    string description;
    bool completed;
};

void add_Task(vector<Task>& tasks) {
    cout << "Enter task description: ";
    string description;
    getline(cin, description);
    //getline to read an entire line

    tasks.emplace_back(description);
    cout << "Task added." << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

void markTaskCompleted(vector<Task>& tasks) {
    cout << "Enter the task number to mark as completed: ";
    size_t index;
    cin >> index;
    cin.ignore();
    if (index == 0 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks[index - 1].completed = true;
    cout << "Task marked as completed." << endl;
}

void removeTask(vector<Task>& tasks) {
    cout << "Enter the task number to remove: ";
    size_t index;
    cin >> index;
    cin.ignore();
    if (index == 0 || index > tasks.size()) {
        cout << "Invalid task number." << endl;
        return;
    }
    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed." << endl;
}

int main() {
    vector<Task> tasks;
    int choice;
    
    do {
        cout << endl << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character left in the buffer
        
        switch (choice) {
            case 1:
                add_Task(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
