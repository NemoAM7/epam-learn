#include<iostream>
using namespace std;

class LivingBeing {
public:
	string name;
	LivingBeing(const string& name) : name(name) {}

	void show() {
		cout << "Name : " << name << endl;
	}
};	

class Animal : virtual public LivingBeing {
public:
	Animal(const string& name) : LivingBeing(name) {}
};


class Plant : virtual public LivingBeing {
public:
	Plant(const string& name) : LivingBeing(name) {}
};

class Hybrid : public Animal, public Plant {
public:
	Hybrid(const string& name) : LivingBeing(name), Animal(name), Plant(name) {}
};


int main() {
	Hybrid chimera("mooli");
	((Animal*)&chimera)->show();
	((Plant*)&chimera)->show();

	cout << &(chimera.Animal::name) << endl;
	cout << &(chimera.Plant::name) << endl;
}