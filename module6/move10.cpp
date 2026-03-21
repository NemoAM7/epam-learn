#include<iostream>
#include<cstring>
#include<utility>

using namespace std;

class Derived {

public:
	char* data;

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

	Derived(Derived&& other) noexcept : data(other.data) {
		other.data = nullptr;
		cout << "moved " << strlen(data) * sizeof(char) << " Bytes from " << static_cast<void*>(other.data) << " to " << static_cast<void*>(data) << endl;
	}

	~Derived() {
		cout << "destructing " << strlen(data) * sizeof(char) << " Bytes from " << static_cast<void*>(data) << endl;
	}

	void print() const {
		std::cout << "MyString: " << (data ? data : "null") << " @ " << static_cast<void*>(data) << std::endl;
	}

};

void printAddress(Derived&& s) {
	cout << "printAddress recieves buffer @ " << (void*)s.data << endl;
}


template<typename T>
void forwardToPrint(T&& str) {
	printAddress(forward<T>(str));
}

int main() {
	Derived s1("lvalue");
	printAddress(std::move(s1));                 // Moves s1

	std::cout << "---" << std::endl;

	printAddress(Derived("rvalue"));            // Moves the temp

	std::cout << "--- Forwarding ---" << std::endl;

	forwardToPrint(Derived("temp"));            // Forwards rvalue (calls move)
	forwardToPrint(std::move(s1));               // Forwards rvalue for moved-from s1

	// Uncomment to see the difference when passing lvalue (would not compile if printAddress only takes rvalue)
	//MyString s2("test");
	//forwardToPrint(s2);    // Would cause compilation error unless you accept lvalue

	return 0;
}