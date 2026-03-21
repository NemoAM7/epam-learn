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

	void print() const {
		std::cout << "MyString: " << (data ? data : "null") << " @ " << static_cast<void*>(data) << std::endl;
	}

};


int main() {
	vector<Derived> arr;

	Derived obj1("first");

	Derived obj2("second");

	cout << "\n arr.push_back(obj1): (copy)" << endl;
	arr.push_back(obj1);

	cout << "\n arr.push_back(move(obj2)): (move) " << endl;
	arr.push_back(move(obj2));

	cout << "\n arr.emplace_back(\"temp\"): " << endl;
	arr.emplace_back("temp");
}



