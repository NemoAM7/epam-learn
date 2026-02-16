#include<iostream>
using namespace std;

// Printable interface
class Printable {
public:
	virtual void print() const = 0;
};


// Savable interface
class Savable {
public:
	virtual void save() const = 0;
};

// Document class implementing both Printable and Savable interfaces
class Document: public Printable, public Savable {
public:
	void print() const override{
		cout << " Document is being printed! " << endl;
	}

	void save() const override {
		cout << " Document is being saved! " << endl;
	}
};

int main() {
	// Create a Document object and use it through both interfaces
	Printable* printable = new Document();
	Savable* savable = new Document();

	// Use the interfaces to call the respective methods
	printable->print();
	savable->save();
}