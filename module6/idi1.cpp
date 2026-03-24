#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class FileWrapper {
	ofstream file;
public:
	FileWrapper(const string& filename) {
		file.open(filename);
		if (!file) throw runtime_error("couldnt open file!");
		cout << "File opened!" << endl;
	}

	~FileWrapper() {
		if (file) {
			file.close();
			cout << "File closed!" << endl;
		}
	}

	ofstream& get() {
		return file;
	}

};

int main() {
	try {
		FileWrapper fw("example.txt");
		fw.get() << "First line." << std::endl;
		fw.get() << "Second line." << std::endl;
		throw std::runtime_error("Simulated crash!");
		fw.get() << "Third line." << std::endl;
	}
	catch (const std::exception& ex) {
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	std::cout << "Back in main, after FileWrapper goes out of scope.\n";
	return 0;
}