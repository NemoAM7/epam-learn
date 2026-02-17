#include<iostream>
#include<vector>
using namespace std;

class Person {
	string name;
	int age;

public:
	Person(string name, int age) : name(name), age(age) {}
	Person(){}
	friend ostream& operator<<(ostream& os, const Person& person);
	friend istream& operator>>(istream& is, Person& person);

};

ostream& operator<<(ostream& os, const Person& person) {
	os << "Name: " << person.name << ", Age: " << person.age << endl;;
	return os;
}

istream& operator>>(istream& is, Person& person) {
	cout << "Name of person: ";
	cin >> person.name;

	cout << "Age of person: ";
	cin >> person.age;

	return is;
}


int main() {
	Person p1, p2, p3;
	cin >> p1 >> p2 >> p3;
	cout << p1 << p2 << p3;
}
