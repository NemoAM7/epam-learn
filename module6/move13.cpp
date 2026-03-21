#include<iostream>
#include<cstring>
#include<utility>
#include<vector>

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
		void* otherp = static_cast<void*>(other.data);
		other.data = nullptr;
		cout << "moved " << strlen(data) * sizeof(char) << " Bytes from " << otherp << " to " << static_cast<void*>(data) << endl;
	}

	~Derived() {
		if (data != nullptr) {
			cout << "destructing " << strlen(data) * sizeof(char) << " Bytes from " << static_cast<void*>(data) << endl;
		}
		delete[] data;
	}

	void print(const char* msg) const {
		std::cout << msg << ": MyString: " << (data ? data : "null") << " @ " << static_cast<void*>(data) << std::endl;
	}

	void reset(const char* str) {
		delete[] data;
		data = new char[strlen(str) + 1];
		strcpy(data, str);
	}

};

int main() {
	Derived s1("abcd");
	Derived s2 = move(s1);

	s1.print("s1 moved from");
	s2.print("s2 moved to");

	s1.reset("reset string");

	s1.print("s1 after reset");

	return 0;
}




