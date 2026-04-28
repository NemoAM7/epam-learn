#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
#include <cctype>

// --- Helper Functions ---

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string toUpperString(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::toupper(c);
        });
    return s;
}

std::string toLowerString(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
    return s;
}

void printTodoList(const std::vector<std::string>& tasks) {
    std::cout << "\n--- Current To-Do List ---\n";
    if (tasks.empty()) {
        std::cout << "[The list is empty]\n";
    }
    else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
    std::cout << "--------------------------\n";
}

// --- TodoList Class ---

class TodoList {
private:
    std::vector<std::string> tasks;

public:
    void initializeTodoList() {
        tasks.clear();
        tasks = { "SendingStatusUpdateMail", "PrepareForMeeting", "CompletingTrainings", "UrgentCriticalBugFix", "KnowledgeTransferNotes" };
        std::cout << "List initialized with default tasks.\n";
        printTodoList(tasks);
    }

    void displayInitialList() {
        printTodoList(tasks);
    }

    void addNewTask() {
        std::cout << "Enter the new task description: ";
        std::string newTask;
        std::getline(std::cin >> std::ws, newTask);
        tasks.push_back(newTask);
        printTodoList(tasks);
    }

    void insertHighPriorityTask() {
        std::cout << "Enter the high-priority task: ";
        std::string highPriorityTask;
        std::getline(std::cin >> std::ws, highPriorityTask);
        // Inserting at the beginning (index 0)
        tasks.insert(tasks.begin(), highPriorityTask);
        std::cout << "Priority task added at the top.\n";
        printTodoList(tasks);
    }

    void viewFirstAndLastTasks() {
        if (tasks.empty()) {
            std::cout << "List is empty.\n";
            return;
        }
        std::cout << "First Task: " << tasks.front() << "\n";
        std::cout << "Last Task: " << tasks.back() << "\n";
    }

    void removeLastTask() {
        if (!tasks.empty()) {
            tasks.pop_back();
            std::cout << "Last task removed.\n";
            printTodoList(tasks);
        }
        else {
            std::cout << "Nothing to remove.\n";
        }
    }

    void markTaskComplete() {
        if (tasks.empty()) return;
        std::cout << "Enter the task number to mark as complete (1-" << tasks.size() << "): ";
        int index;
        if (std::cin >> index && index > 0 && index <= (int)tasks.size()) {
            tasks.erase(tasks.begin() + (index - 1));
            std::cout << "Task completed and removed.\n";
            printTodoList(tasks);
        }
        else {
            std::cout << "Invalid index.\n";
            clearInputBuffer();
        }
    }

    void sortTasksAlphabetically() {
        std::sort(tasks.begin(), tasks.end());
        std::cout << "Tasks sorted alphabetically.\n";
        printTodoList(tasks);
    }

    void reverseTaskOrder() {
        std::cout << "\n--- Reverse Task Order ---\n";
        if (tasks.empty()) {
            std::cout << "The list is empty. No tasks to reverse.\n";
        }
        else {
            std::cout << "Reversing task order...\n";
            std::reverse(tasks.begin(), tasks.end());
            printTodoList(tasks);
        }
    }

    void searchAndCountTasks() {
        std::cout << "Enter task name to search for: ";
        std::string query;
        std::getline(std::cin >> std::ws, query);

        auto it = std::find(tasks.begin(), tasks.end(), query);
        if (it != tasks.end()) {
            std::cout << "Task found at position: " << std::distance(tasks.begin(), it) + 1 << "\n";
        }
        else {
            std::cout << "Task not found.\n";
        }

        long count = std::count(tasks.begin(), tasks.end(), query);
        std::cout << "Total occurrences: " << count << "\n";
    }

    void transformToUppercase() {
        for (auto& task : tasks) {
            task = toUpperString(task);
        }
        std::cout << "All tasks transformed to UPPERCASE.\n";
        printTodoList(tasks);
    }

    void checkKeywordContainingTasks() {
        bool found = std::any_of(tasks.begin(), tasks.end(), [](const std::string& s) {
            std::string upper = toUpperString(s);
            return upper.find("URGENT") != std::string::npos || upper.find("DEADLINE") != std::string::npos;
            });

        if (found) {
            std::cout << "Alert: You have urgent or deadline-sensitive tasks in your list!\n";
        }
        else {
            std::cout << "No urgent or deadline keywords found.\n";
        }
    }

    void findLexicographicallyFirstLast() {
        if (tasks.empty()) return;
        auto minIt = std::min_element(tasks.begin(), tasks.end());
        auto maxIt = std::max_element(tasks.begin(), tasks.end());
        std::cout << "Lexicographically First: " << *minIt << "\n";
        std::cout << "Lexicographically Last: " << *maxIt << "\n";
    }

    void finalCleanup() {
        tasks.clear();
        std::cout << "All tasks cleared.\n";
        if (tasks.empty()) std::cout << "Verification: List is now empty.\n";
    }
};

// --- Main Menu Interface ---

int main() {
    TodoList myTodoList;
    int choice;

    myTodoList.initializeTodoList();

    do {
        std::cout << "\n========== TO-DO MANAGER ==========\n";
        std::cout << "1. Initialize/Reset List\n";
        std::cout << "2. Display Current List\n";
        std::cout << "3. Add New Task\n";
        std::cout << "4. Insert High-Priority Task\n";
        std::cout << "5. View First and Last Tasks\n";
        std::cout << "6. Remove Last Task\n";
        std::cout << "7. Mark Task as Complete (By Index)\n";
        std::cout << "8. Sort Alphabetically\n";
        std::cout << "9. Reverse Task Order\n";
        std::cout << "10. Search and Count Tasks\n";
        std::cout << "11. Transform to UPPERCASE\n";
        std::cout << "12. Check for Urgent Keywords\n";
        std::cout << "13. Find Lexicographical Min/Max\n";
        std::cout << "14. Clear All Tasks\n";
        std::cout << "0. Exit\n";
        std::cout << "Select an option: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        switch (choice) {
        case 1: myTodoList.initializeTodoList(); break;
        case 2: myTodoList.displayInitialList(); break;
        case 3: myTodoList.addNewTask(); break;
        case 4: myTodoList.insertHighPriorityTask(); break;
        case 5: myTodoList.viewFirstAndLastTasks(); break;
        case 6: myTodoList.removeLastTask(); break;
        case 7: myTodoList.markTaskComplete(); break;
        case 8: myTodoList.sortTasksAlphabetically(); break;
        case 9: myTodoList.reverseTaskOrder(); break;
        case 10: myTodoList.searchAndCountTasks(); break;
        case 11: myTodoList.transformToUppercase(); break;
        case 12: myTodoList.checkKeywordContainingTasks(); break;
        case 13: myTodoList.findLexicographicallyFirstLast(); break;
        case 14: myTodoList.finalCleanup(); break;
        case 0: std::cout << "Exiting program...\n"; break;
        default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}