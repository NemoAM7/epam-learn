#include<iostream>
#include<string>
#include<functional>

using namespace std;

void greet(const string& name) {
	cout << "Hello, " << name << "!" << endl;
}

void invokeCallback(function<void(const string&)> callback, const string& name) {
	callback(name);
}

int main() {
	invokeCallback(greet, "Alice");

	string host = "mooli";
	invokeCallback([](const string& n) {
		cout << "Hey there! " << n << endl;
		}, "Bob");

	invokeCallback([&host](const string& n) {
		cout << host << " says: Hey there! " << n << endl;
		}, "Bob");



	return 0;
}