#include<iostream>
using namespace std;

class BaseLogger {
public:
	virtual ~BaseLogger() {
		cout << "Base Logger Destructor called!" << endl;
	};

	virtual void log(const std::string& message) = 0;

};

class FileLogger : public BaseLogger {
public:
	~FileLogger() {
		cout << "File Logger Destructor called!" << endl;
	};

	void log(const std::string& message) {
		cout << "[File] " << message << endl;
	}

};

class ConsoleLogger : public BaseLogger {
public:
	~ConsoleLogger() {
		cout << "Console Logger Destructor called!" << endl;
	};

	void log(const std::string& message) {
		cout << "[Console] " << message << endl;
	}

};

int main() {
	BaseLogger* logger1 = new ConsoleLogger();
	BaseLogger* logger2 = new FileLogger();

	logger1->log("Hi");
	logger2->log("bye");

	delete logger1;
	delete logger2;
}