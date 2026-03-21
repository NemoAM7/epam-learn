#include<iostream>
#include<string>
using namespace std;

void greetMorning(const string& name) {
	cout << "Good morning, " << name << "!" << endl;
}

void greetEvening(const string& name) {
	cout << "Good evening, " << name << "!" << endl;
}

void invokeCallback(void (*callback)(const string&), const string& name) {
	callback(name);
}

int main() {
	invokeCallback(greetMorning, "Alice");
	invokeCallback(greetEvening, "Bob");
	return 0;
}