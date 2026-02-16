#include<iostream>
using namespace std;

class BaseLogger {
public:
	virtual ~BaseLogger() {
		cout << "Base Logger Destructed!" << endl;
	};
};

class FileLogger : public BaseLogger {
public:
	~FileLogger() {
		cout << "File Logger Destructed!" << endl;
	};
};

class ConsoleLogger : public BaseLogger {
public:
	~ConsoleLogger() {
		cout << "Console Logger Destructed!" << endl;
	};
};

int main() {
	BaseLogger* logger1 = new ConsoleLogger();
	BaseLogger* logger2 = new FileLogger();


	delete logger1;
	delete logger2;
}