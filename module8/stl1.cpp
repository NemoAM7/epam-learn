#include<iostream>
#include<stdexcept>
#include<vector>
int main() {

	std::vector<int> grades;

	if (grades.empty()) {
		std::cout << "Array is empty!" << std::endl;
	}
	else {
		std::cout << "Array is not empty!" << std::endl;
	}

	grades.push_back(80);
	grades.push_back(67);
	grades.push_back(90);
	grades.push_back(75);
	grades.push_back(98);
	grades.push_back(89);

	std::cout << "Size of array: " << grades.size() << std::endl;
	for (int grade : grades) {
		std::cout << grade << " ";
	}
	std::cout << std::endl;

	std::cout << "Front: " << grades.front() << std::endl;
	std::cout << "Back: " << grades.back() << std::endl;

	std::cout << "Value at index 2 (using subscript): " << grades[2] << std::endl;
	std::cout << "Value at index 2 (using at()): " << grades.at(2) << std::endl;

	grades[2] = 20;

	std::cout << "Value at index 2 (using subscript): " << grades[2] << std::endl;
	std::cout << "Value at index 2 (using at()): " << grades.at(2) << std::endl;

	try {
		std::cout << grades.at(10) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << "at() failed, please pass a valid index" << std::endl;
	}

	grades.insert(grades.begin(), 100);
	grades.insert(grades.end() - 1, 32);

	std::cout << "Size of array: " << grades.size() << std::endl;
	for (int grade : grades) {
		std::cout << grade << " ";
	}
	std::cout << std::endl;

	grades.pop_back();
	grades.erase(grades.begin() + 1);

	std::cout << "Size of array: " << grades.size() << std::endl;
	for (int grade : grades) {
		std::cout << grade << " ";
	}
	std::cout << std::endl;

	grades.clear();
	std::cout << "Size of array: " << grades.size() << std::endl;
	if (grades.empty()) {
		std::cout << "Array is empty!" << std::endl;
	}
	else {
		std::cout << "Array is not empty!" << std::endl;
	}
}