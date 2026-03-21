#include<iostream>
using namespace std;

class Buffer {
	int* data;
	size_t size;

public:
	Buffer(size_t size) : size(size) {
		data = new int[size];
		for (int i = 0; i < size; i++) {
			data[i] = i;
		}
	}

	Buffer(Buffer& other) : size(other.size) {
		data = new int[size];
		memcpy(other.data, data, sizeof(int) * size);
	}

	Buffer(Buffer&& other) : size(other.size), data(other.data) {
		other.data = nullptr;
		other.size = 0;
	}

	Buffer& operator=(Buffer& other) {
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = new int[size];
			memcpy(other.data, data, sizeof(int) * size);
		}
		
		return *this;
	}

	Buffer& operator=(Buffer&& other){
		if (this != &other) {
			delete[] data;
			size = other.size;
			data = other.data;
			other.data = nullptr;
			other.size = 0;
		}

		return *this;
	}

	~Buffer() {
		delete[] data;
	}

	void print(const string& message) const {
		cout << message << ": ";
		for (int i = 0; i < size; i++) {
			cout << data[i] << " ";
		}
		cout << " at " << static_cast<void*>(data) << endl;
	}


};
int main() {
	Buffer a(3);
	Buffer b = a; 
	Buffer c(2);
	c = a;        

	Buffer d = std::move(a);
	Buffer e(1);
	e = std::move(c);  

	b.print("b");
	d.print("d");
	e.print("e");

	return 0;
}