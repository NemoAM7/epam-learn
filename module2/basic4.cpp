#include<iostream>
using namespace std;

class Item {
public:
	Item(){
		cout << "Constructed an Item objects at " << this << endl;
	}

	~Item(){
		cout << "Destructed an Item object at " << this << endl;
	}
};


int main() {
	Item* item = new Item(); // calls constructor for a single item
	Item* items = new Item[3]; // calls constructor for three items 

	delete item; // calls destructor for a single item
	delete[] items; // calls desturctor for all elements in the array

	Item* item2 = new Item(); // calls constructor for a single item
	delete[] item2; // undefined behavior: using delete[] on a single object

	Item* items2 = new Item[2]; // calls constructor for two items
	delete items2; // undefined behavior: using delete on an array

	return 0;
}