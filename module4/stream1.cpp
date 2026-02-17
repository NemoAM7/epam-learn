#include<iostream>
#include<string>
using namespace std;
int main() {
	string name;
	int age;
	string city;

	cout << "What is your name?" << endl;
	getline(cin, name);

	cout << "What is your age?" << endl;
	cin >> age;

	cin.ignore();

	cout << "What is your city?" << endl;
	getline(cin, city);

	cout << "Greetings fellow traveller " << name << " from the far lands of " << city << " standing strong at the age of " << age << " years young!" << endl;
}