#include <ios>
#include <iostream>
#include <fstream>
#include <limits>
#include <ostream>
#include <string>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

void display_menu();
void add(std::vector<Task>&tasks, std::ofstream&outputFile);
void del(std::vector<Task>&tasks);
void view(std::vector<Task>tasks);

int main(void) {
    std::ofstream outputFile("tasks.txt");
    std::vector<Task> tasks;

    if (!outputFile.is_open()) {
        std::cout << "Failed to find tasks file!";
        return 0;
    }

    std::cout << "Welcome to Task Manager!\n";
    display_menu();

    int x = 0;
    while (std::cin >> x) {
        std::cout << '\n';
        if (x == 1) {
            add(tasks, outputFile);
        } else if (x == 2) {
            del(tasks);
        } else if (x == 3) {
            view(tasks);
        } else if (x == 4) {
            break;
        } else if (x < 1 || x > 4) {
            std::cout << "Enter a valid option!\n";
        }
        display_menu();
    }
    return 0;
}

void display_menu() {
    std::cout << '\n';
    std::cout << "Enter the number corresponding to the following:" << std::endl;
    std::cout << '\n';
    std::cout << "1. Add task\n";
    std::cout << "2. Delete task\n";
    std::cout << "3. View tasks\n";
    std::cout << "4. Save and exit\n";
}

void add(std::vector<Task>&tasks, std::ofstream&outputFile) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string userInput;
    std::cout << "Enter task description: ";
    while (std::getline(std::cin, userInput)) {
        outputFile << userInput << std::endl;
        Task newTask{userInput, false};
        tasks.push_back(newTask);
        std::cout << "Task added!\n";
        std::cout << '\n';
        std::cout << "Enter task description: ";
    }
}

void del(std::vector<Task>&tasks) {
    if (tasks.size() == 0) {
        std::cout << "No tasks!" << std::endl;
        return;
    }
    std::cout << "Which task to be deleted?" << std::endl;
    view(tasks);
    std::cout << std::endl;
    int x = 0;
    std::cin >> x;
    std::vector<Task> temp;
    for (int i = 0; i < tasks.size(); i++) {
        Task newTask = tasks[i];
        if (i != x) {
            temp.push_back(newTask);
        }
    }
    tasks = temp;
    std::cout << "Task deleted!" << std::endl;
    std::cout << '\n';
    std::cout << "Updated list of tasks:" << std::endl;
    std::cout << '\n';
    view(tasks);
}

void view(std::vector<Task>tasks) {
    if (tasks.size() == 0) {
        std::cout << "No tasks!" << std::endl;
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << "Task " << i << ": " << tasks[i].description << ", ";
        if (tasks[i].completed == false) {
            std::cout << "Uncompleted.." << std::endl;
        } else {
            std::cout << "Completed!" << std::endl;
        }
    }
}