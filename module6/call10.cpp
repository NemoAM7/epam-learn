#include<iostream>
#include<functional>
#include<string>
using namespace std;

void invokeCallback(function<void(const string&)> callback, const string& name) {
	callback(name);
}

int main() {
	invokeCallback([](const string& n) {
		cout << "Lambda callback says: Welcome, " << n << "!" << endl;
		;
		}, "Mooli");

	return 0;
}