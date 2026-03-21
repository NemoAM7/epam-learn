#include<iostream>
using namespace std;

class ResourceHolder {
	int* data;
	size_t size;
public:
	ResourceHolder(size_t sz) : size(sz) {
		data = new int[size];
		for (size_t i = 0; i < size; ++i) {
			data[i] = i;
		}
		cout << "Constructor allocated " << sizeof(int) * size << " Bytes at " << static_cast<void*>(data) << endl;
	}

	ResourceHolder(const ResourceHolder& other) : size(other.size) {
		data = new int[size];
		memcpy(data, other.data, sizeof(int) * size);
		cout << "Copy Constructor copied " << sizeof(int) * size << " Bytes from " << static_cast<void*>(other.data) << " to " << static_cast<void*>(data) << endl;
	}

	ResourceHolder& operator=(const ResourceHolder& other) {
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = new int[size];
			memcpy(data, other.data, sizeof(int) * size);
			cout << "Assignment copied " << sizeof(int) * size << " Bytes from " << static_cast<void*>(other.data) << " to " << static_cast<void*>(data) << endl;
		}
		return *this;
	}

	~ResourceHolder() {
		cout << "Clearing memory: " << sizeof(int) * size << " Bytes at " << static_cast<void*>(data);
		delete[] data;	
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
		cout << "at " << static_cast<void*>(data) << endl;
	}
};

int main() {
	ResourceHolder r(10);
	ResourceHolder s(r);
	ResourceHolder t(3);

	s.print();

	s = t;
	
	t.print();
	r.print();
	s.print();
}
