#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Wrapper {
public:

	vector<int> data;
	string label;
	Wrapper(string l, initializer_list<int> il) : data(il), label(move(l)) {}

	void print(const char* tag) const {
		cout << tag << "label: " << label << ", data: ";
		for (int x : data) {
			cout << x << " ";
		}
		cout << "[data@" << static_cast<const void*>(data.data()) << "]" << endl;
	}
};



int main() {
	Wrapper w1("first", { 1,2,3 });
	w1.print("w1:");

	Wrapper w2 = w1;        // Copy
	w2.label = "copy";
	w2.print("w2:");

	Wrapper w3 = std::move(w1); // Move
	w3.label = "moved";
	w3.print("w3:");
	w1.print("w1 after move:"); // w1's data is valid but unspecified (empty/moved-from)

	return 0;
}