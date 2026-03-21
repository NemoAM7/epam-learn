#include<iostream>
#include<string>

using namespace std;

void greet(const string& name) {
	cout << "Hello, " << name << "!" << endl;
}

void invokeCallback(void callback(const string&), const string& name) {
	callback(name);
}

int main() {
	invokeCallback(greet, "Alice");
	return 0;
}