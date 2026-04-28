#include<iostream>
#include<list>
#include<algorithm>

struct Task {
	std::string name;
	int priority;
	int deadline;

	void print() const {
		std::cout << "=======================" << std::endl;
		std::cout << "Name:" << name << std::endl;
		std::cout << "Priority:" << priority << std::endl;
		std::cout << "Deadline:" << deadline << std::endl;
	}
};

bool predicate(struct Task t1, struct Task t2) {
	if (t1.priority > t2.priority) return true; // swap by priority (descending)
	if (t1.priority < t2.priority) return false;
	if (t1.deadline > t2.deadline) return false; // if priority equal swap by deadline (ascending)
	return true;
}

int main() {
	std::list<Task> tasks = { {"Sending the Mail", 2, 5}, {"Fix Critical bug", 1, 1}, {"Team meeting", 2, 1}, {"Code review", 2, 3}, {"Update docs", 3, 4} };
	for (const Task& task : tasks) task.print();
	std::cout << "\nSorting...\n\n";
	tasks.sort(predicate);
	for (const Task& task : tasks) task.print();
}