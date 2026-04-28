#include <iostream>
#include <queue>
#include <vector>
#include <string>

// Define the Patient data structure
struct Patient {
    std::string name;
    int severity;    // 1 (Critical) to 5 (Least)
    int arrivalTime; // Minutes since opening

    // Constructor for easy initialization
    Patient(std::string n, int s, int t) : name(n), severity(s), arrivalTime(t) {}
};

// Custom Comparator
struct ComparePatients {
    bool operator()(const Patient& p1, const Patient& p2) const {
        // Rule 1: Severity. Higher number means lower priority.
        // Return true if p1 is LESS important than p2.
        if (p1.severity > p2.severity) {
            return true;
        }
        if (p1.severity < p2.severity) {
            return false;
        }

        // Rule 2: Arrival Time (Tie-breaker).
        // If severities are equal, the one who arrived LATER (larger time) 
        // has LOWER priority.
        return p1.arrivalTime > p2.arrivalTime;
    }
};

int main() {
    // Declaration: <DataType, UnderlyingContainer, Comparator>
    std::priority_queue<Patient, std::vector<Patient>, ComparePatients> erQueue;

    // Adding patients to test the logic
    erQueue.push(Patient("Alice Smith", 3, 10)); // S3, A10
    erQueue.push(Patient("Bob Jones", 1, 5));     // S1, A5 (Should be 1st)
    erQueue.push(Patient("Charlie Brown", 3, 8)); // S3, A8 (Should be before Alice)
    erQueue.push(Patient("David Miller", 2, 12)); // S2, A12
    erQueue.push(Patient("Eve Adams", 1, 7));     // S1, A7 (Should be after Bob)
    erQueue.push(Patient("Frank White", 5, 2));   // S5, A2 (Should be last)

    std::cout << "--- Emergency Room Triage Sequence ---" << std::endl;

    // Processing loop
    while (!erQueue.empty()) {
        Patient current = erQueue.top(); // Get the "highest priority" patient

        std::cout << "Processing: " << current.name
            << " | Severity: " << current.severity
            << " | Arrived: " << current.arrivalTime << " min"
            << std::endl;

        erQueue.pop(); // Remove from queue
    }

    return 0;
}