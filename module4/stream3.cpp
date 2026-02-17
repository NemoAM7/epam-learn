#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	string file_name;
	string text;

	cout << "What is the file name: ";
	cin >> file_name;

	cin.ignore();

	cout << "What is the text you want to store: ";
	cin >> text;

	ofstream out_file(file_name, ios::out);

	if (out_file.is_open()) {
		out_file << text;

		cout << "Succesfully saved the text!" << endl;

		out_file.close();
	}
	else {
		cout << "Error opening the file!";
	}

	ifstream in_file(file_name, ios::in);
	string line;

	if (in_file.is_open()){
		cout << "Opening and printing file " << file_name << endl;
		while (getline(in_file, line)) {
			cout << line << endl;
		}
	}
	else {
		cout << "Error while opening the file!" << endl;
	}
}