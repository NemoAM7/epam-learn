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

	Derived& operator=(Derived&& other) noexcept {
		if (this != &other) {
			delete[] data;
			data = other.data;
			other.data = nullptr;
		}
		return *this;
	}

	~Derived() {
		if (data) {
			cout << "Data deleted! at " << static_cast<const void*>(data) << endl;
			delete[] data;
			data = nullptr;
		}
		else {
			cout << "Double delete!" << endl;
		}
	}

	void print() const {
		cout << "\"" << data << "\" at " << static_cast<const void*>(data) << endl;
	}
};

int main() {
	Derived a("sample");
	Derived b("");
	b = move(a);
	Derived c = b;
	return 0;
}