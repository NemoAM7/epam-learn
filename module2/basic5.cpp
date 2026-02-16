#include<iostream>
using namespace std;

class LeakDemo {
	public:
	LeakDemo() {
		cout << "Memory allocated at " << this << endl;
	}
	~LeakDemo() {
		cout << "Memory deallocated at " << this << endl;
	}
};

int main() {
	for (int i = 0; i < 1000; i++) {
		LeakDemo* obj = new LeakDemo();
        delete obj;
    }


}