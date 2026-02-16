#include<iostream>
using namespace std;

class Tracker {
public:

	// static count data members storing the amount of objects left 
	static int count;

	// creates a new object and increments the object count
	// overloads new operator
	void* operator new(size_t size) {
		cout << "Allocating " << size << " bytes\n";
		count++;
		cout << "Objects created: " << Tracker::count << endl;
		void* ptr = ::operator new(size); // use new from global namespace
		return ptr;
	}

	// destroys the object and decrements the object count
	// overloads the delete operator
	void operator delete(void* ptr) {
		cout << "Deallocating memory\n";
		count--;
		cout << "Object left: " << Tracker::count << endl;
		::delete(ptr); // use delete from global namespace
	}
};

int Tracker::count = 0;

int main(){

	// create trackers
	Tracker* t1 = new Tracker();
	Tracker* t2 = new Tracker();
	Tracker* t3 = new Tracker();

	// delete a few
	delete t1;
	delete t3;

	// check if any tracker object was left undestructed
	if (Tracker::count > 0) {
		cout << "Warning! Count of objects not destoryed: " << Tracker::count << endl;
		return 1;
	}

	cout << "Zero objects left. All good!" << endl;

	return 0;
}