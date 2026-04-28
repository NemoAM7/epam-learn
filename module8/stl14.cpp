struct Student {
    int id;
    std::string name;
    bool active;
    double grade;

    Student(int i, std::string n, bool a, double g)
        : id(i), name(n), active(a), grade(g) {
    }
};

// ========== DANGEROUS CODE TO REFACTOR ==========   
class StudentRoster {
private:
    std::vector<Student> studentsVector;      // Using vector
    std::list<Student> studentsList;          // Using list
    std::map<int, Student> studentsMap;       // Using map

public:
    // BUG 1: Vector erase with range-based for loop
    void removeFailedStudentsVector() {
        for (auto& student : studentsVector) {
            if (student.grade < 60.0) {
                // BUG: Invalidates iterator
                studentsVector.erase(&student);
            }
        }
    }

    // BUG 2: Manual loop with wrong iterator handling
    void removeInactiveStudentsList() {
        auto it = studentsList.begin();
        while (it != studentsList.end()) {
            if (!it->active) {
                studentsList.erase(it);
                // BUG: Continues using invalid iterator
            }
            ++it;  // BUG: Double increment after erase
        }
    }

    // BUG 3: Map erase with potential issues
    void removeLowGradesMap(double threshold) {
        for (auto it = studentsMap.begin(); it != studentsMap.end(); ++it) {
            if (it->second.grade < threshold) {
                // BUG: Invalidates current iterator
                studentsMap.erase(it);
            }
        }
    }

    // BUG 4: Trying to erase while iterating incorrectly
    void cleanupVector() {
        for (size_t i = 0; i < studentsVector.size(); ++i) {
            if (studentsVector[i].grade < 60.0 || !studentsVector[i].active) {
                // BUG: Index invalidation
                studentsVector.erase(studentsVector.begin() + i);
                // BUG: Skips next element
            }
        }
    }

    // Helper to add students
    void addStudent(int id, std::string name, bool active, double grade) {
        Student s(id, name, active, grade);
        studentsVector.push_back(s);
        studentsList.push_back(s);
        studentsMap[id] = s;
    }

    // Print all students
    void printRoster() {
        std::cout << "Vector (" << studentsVector.size() << "): ";
        for (const auto& s : studentsVector)
            std::cout << s.name << "(" << s.grade << ") ";

        std::cout << "\nList (" << studentsList.size() << "): ";
        for (const auto& s : studentsList)
            std::cout << s.name << "(" << s.grade << ") ";

        std::cout << "\nMap (" << studentsMap.size() << "): ";
        for (const auto& [id, s] : studentsMap)
            std::cout << s.name << "(" << s.grade << ") ";

        std::cout << "\n---\n";
    }
};
// ========== YOUR REFACTORING TARGETS ==========

int main() {
    StudentRoster roster;

    // Test data
    roster.addStudent(1, "Alice", true, 95.5);
    roster.addStudent(2, "Bob", false, 45.0);     // Inactive, failing
    roster.addStudent(3, "Charlie", true, 58.5);   // Failing
    roster.addStudent(4, "Diana", true, 88.0);
    roster.addStudent(5, "Eve", false, 30.0);      // Inactive, failing

    std::cout << "Initial roster:\n";
    roster.printRoster();

    // These calls have iterator invalidation bugs!
    // Your task: Refactor these methods
    roster.removeFailedStudentsVector();   // Remove grade < 60
    roster.removeInactiveStudentsList();   // Remove inactive
    roster.removeLowGradesMap(50.0);       // Remove grade < 50
    roster.cleanupVector();                // Complex cleanup

    std::cout << "\nAfter removals (should be bug-free):\n";
    roster.printRoster();

    return 0;
}
