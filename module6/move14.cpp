#include<iostream>
using namespace std;

class Base {
	int* baseData;
public:
	Base() : baseData(new int(0)) {
		cout << "Constructor called, dynamic value initialized at " << baseData << endl;
	}

	Base(const Base& other) : baseData(new int(*other.baseData)) {
		cout << "Copy constructor called, dynamic value copied from " << other.baseData << " to " << baseData << endl;
	}

	Base(Base&& other) noexcept : baseData(other.baseData) {
		cout << "Move constructor called, dynamic value moved from " << other.baseData << endl;
		other.baseData = nullptr;
	}

	Base& operator=(const Base& other) {
		if (this != &other) {
			*baseData = *other.baseData;
			cout << "Copy assignment called, dynamic value copied from " << other.baseData << " to " << baseData << endl;
		}
		return *this;
	}

	Base& operator=(Base&& other) noexcept {
		if (this != &other) {
			delete baseData;
			baseData = other.baseData;
			cout << "Move assignment called, dynamic value moved from " << other.baseData << endl;
			other.baseData = nullptr;
		}
		return *this;
	}

	virtual ~Base() {
		cout << "Destructor called (base) memory freed at " << baseData << endl;
		delete baseData;
	}

	virtual void print(const char* label) const {
		cout << label << ": " << (baseData ? (*baseData) : 0) << " at " << baseData << endl;
	}
};

class Derived : public Base {
	char* data;

public:
	Derived() : data(new char[8]), Base() {
		strcpy(data, "abcd123");
		cout << "initialized " << strlen(data) * sizeof(char) << " Bytes at " << static_cast<void*>(data) << endl;
	}

	Derived(const Derived& other) : Base(other) {
		data = new char[strlen(other.data) + 1];
		strcpy(data, other.data);
		cout << "copied " << strlen(data) * sizeof(char) << " Bytes from " << static_cast<void*>(other.data) << " to " << static_cast<void*>(data) << endl;
	}

	Derived(Derived&& other) noexcept : data(other.data), Base(move(other)) {
		void* otherp = static_cast<void*>(other.data);
		other.data = nullptr;
		cout << "moved " << strlen(data) * sizeof(char) << " Bytes from " << otherp << " to " << static_cast<void*>(data) << endl;
	}

	Derived& operator=(Derived& other) {
		if (this != &other) {
			Base::operator=(other);
			delete[] data;
			data = new char[strlen(other.data) + 1];
			strcpy(other.data, data);
			std::cout << "Derived copy assign: " << static_cast<void*>(data) << '\n';
		}

		return *this;
	}

	Derived& operator=(Derived&& other) noexcept {
		if (this != &other) {
			Base::operator=(move(other));
			delete[] data;
			data = other.data;
			other.data = nullptr;
			std::cout << "Derived move assign: " << static_cast<void*>(data) << '\n';
		}

		return *this;
	}

	~Derived() override {
		if (data != nullptr) {
			cout << "destructing derived " << strlen(data) * sizeof(char) << " Bytes from " << static_cast<void*>(data) << endl;
			delete[] data;
		}
	}

	void print(const char* label) const override {
		Base::print("base: ");
		std::cout << label << ": " << (data ? data : "null") << " @ " << static_cast<void*>(data) << std::endl;
	}

};
int main() {
	std::cout << "--- Base test ---\n";
	Base b1;
	Base b2 = b1;       // Copy
	b2 = std::move(b1); // Move assign

	std::cout << "--- Derived test ---\n";
	Derived d1;
	Derived d2 = d1;    // Copy ctor
	d2 = std::move(d1); // Move assign

	std::cout << "--- Slicing demo ---\n";
	Base sliced = d2;   // Slicing (loses Derived-specific data)
	sliced.print("sliced: ");
	d2.print("d2: ");

	std::cout << "--- Polymorphic deletion ---\n";
	Base* poly = new Derived();
	delete poly;        // Should call both destructors safely
	return 0;
}