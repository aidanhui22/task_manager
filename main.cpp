#include <ios>
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

void add(std::vector<Task>&tasks, std::ofstream&outputFile);
void del();
void view();

int main(void) {
    std::ofstream outputFile("tasks.txt");
    std::vector<Task> tasks;

    if (!outputFile.is_open()) {
        std::cout << "Failed to find tasks file!";
        return 0;
    }

    std::cout << "Welcome to Task Manager!\n";
    std::cout << "1. Add task\n";
    std::cout << "2. Delete task\n";
    std::cout << "3. View tasks\n";
    std::cout << "4. Save and exit\n";

    int x = 0;
    while (std::cin >> x) {
        std::cout << '\n';
        if (x == 1) {
            add(tasks, outputFile);
        } else if (x == 2) {
            del();
        } else if (x == 3) {
            view();
        } else if (x == 4) {
            break;
        } else if (x < 1 || x > 4) {
            std::cout << "Enter a valid option!\n";
        }
        std::cout << "1. Add task\n";
        std::cout << "2. Delete task\n";
        std::cout << "3. View tasks\n";
        std::cout << "4. Save and exit\n";
    }
    return 0;
}


void add(std::vector<Task>&tasks, std::ofstream&outputFile) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string userInput;
    std::cout << "Enter task description: ";
    std::getline(std::cin, userInput);
    outputFile << userInput << std::endl;
    Task newTask{userInput, false};
    tasks.push_back(newTask);
    std::cout << "Task added!\n";
    std::cout << '\n';
}

void del() {

}

void view() {

}