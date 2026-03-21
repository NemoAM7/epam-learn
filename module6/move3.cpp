#include<iostream>
using namespace std;

class Derived {
	char* data;
public:
	Derived(const char* str) {
		data = new char[strlen(str) + 1];
		memcpy(data, str, strlen(str) + 1);
	}

	Derived(const Derived& other) {
		data = new char[strlen(other.data) + 1];
		memcpy(data, other.data, strlen(other.data) + 1);
	}

	Derived(Derived&& other) noexcept : data(other.data) {
		other.data = nullptr;
	}

	Derived& operator=(const Derived& other) {
		if (this != &other) {
			delete[] data;
			data = new char[strlen(other.data) + 1];
			memcpy(data, other.data, strlen(other.data) + 1);
		}

		return *this;
	}

	~Derived() {
		delete[] data;
		data = nullptr;
	}

	void print() const {
		cout << "\"" << data << "\" at " << static_cast<const void*>(data) << endl;
	}
};

int main() {
	Derived a("abcd");
	a.print();

	Derived b = move(a);
	b.print();

	return 0;
}