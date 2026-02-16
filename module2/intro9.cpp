#include<iostream>
using namespace std;


// Logger class
class Logger {
	// mutable access count member
	mutable int accessCount;
	
	// message to print while print() is called
	string message;
public:

	// Constructor to initialize the message and access count
	Logger(const string& msg) : message(msg), accessCount(0) {}

	// prints the message with the access count after incrementing it
	void print() const {
		cout << message << ++accessCount << endl;
	}

	// getter for access count
	int getAccessCount() const {
		return accessCount;
	}

};

int main() {

	// Object created for logger class
	Logger logger("Logger triggered! Access count : ");

	// print initial access count
	cout << "Logger access count: " << logger.getAccessCount() << endl;

	// log 3 times
	logger.print();
	logger.print();
	logger.print();

	// print final access count
	cout << "Logger access count: " << logger.getAccessCount() << endl;

	return 0;
}
