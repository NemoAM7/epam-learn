#include<iostream>
using namespace std;

class Derived {
	char* data;
public:
	Derived(const char* buffer) {
		data = new char[strlen(buffer) + 1];
		strcpy(data, buffer);
		cout << "initialized " << strlen(data) * sizeof(char) << " Bytes at " << static_cast<void*>(data) << endl;
	}

	Derived(const Derived& other) {
		data = new char[strlen(other.data) + 1];
		strcpy(data, other.data);
		cout << "copied " << strlen(data) * sizeof(char) << " Bytes from " << static_cast<void*>(other.data) << " to " << static_cast<void*>(data) << endl;
	}

	Derived(Derived&& other) : data(other.data) {
		other.data = nullptr;
		cout << "moved " << strlen(data) * sizeof(char) << " Bytes from " << static_cast<void*>(other.data) << " to " << static_cast<void*>(data) << endl;
	}

	~Derived() {
		cout << "destructing " << strlen(data) * sizeof(char) << " Bytes from " << static_cast<void*>(data) << endl;
	}

	void print() const {
		std::cout << "MyString: " << (data ? data : "null") << std::endl;
	}

};

Derived makeString() {
	Derived temp("Hello from makeString!");
	return temp;
}

int main() {
	Derived s = makeString();
	s.print();
	return 0;
}