#include<iostream>
#include<exception>

using namespace std;

static int counter = 0;

class SystemError : public runtime_error {
	const char* message;
public:
	SystemError(const char* message) : message(message), runtime_error(message) {}
	virtual const char* what() const noexcept override {
		return message;
	}
};

class NetworkError : public runtime_error {
	const char* message;
public:
	NetworkError(const char* message) : message(message), runtime_error(message) {}
	virtual const char* what() const noexcept override {
		return message;
	}
};

void complexOperation() {
	counter++;

	if (counter == 1) {
		throw SystemError("System error caught: Counter is set to 1");
	}
	else if (counter == 2) {
		throw NetworkError("Network Error caught: Counter is set to 2");
	}
	else if (counter == 3) {
		throw - 1;
	}
	else if (counter == 4) {
		throw "Very unexpected Error!";
	}
	else {
		cout << "Operation completed successfully" << endl;
	}
}

void resetCounter() {
	counter = 0;
}


int main() {
	for (int i = 0; i < 10; i++) {
		try {
			complexOperation();
		}
		catch (const NetworkError e) {
			cout << e.what() << endl;
		}
		catch (const SystemError e) {
			cout << e.what() << endl;
		}
		catch (const int& code) {
			cout << "Generic integer error caught: " << code << endl;
		}
		catch (const char* msg) {
			cout << "Unknown exception caught: " << msg << endl;
		}
	}

	resetCounter();

	for (int i = 0; i < 10; i++) {
		try {
			complexOperation();
		}
		catch (const NetworkError e) {
			cout << e.what() << endl;
		}
		catch (const SystemError e) {
			cout << e.what() << endl;
		}
		catch (const int& code) {
			cout << "Generic integer error caught: " << code << endl;
		}
		catch (const char* msg) {
			cout << "Unknown exception caught: " << msg << endl;
		}
	}

}