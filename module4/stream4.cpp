#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	string in_file_name;
	string out_file_name;

	cout << "What is the infile name: ";
	cin >> in_file_name;

	cin.ignore();

	cout << "What is the outfile name: ";
	cin >> out_file_name;

	ofstream out_file(out_file_name, ios::out);
	ifstream in_file(in_file_name, ios::in);
	string line;
	int index = 0;

	if (in_file.is_open() && out_file.is_open()){
		cout << "Opening file " << in_file_name << " and copying contents to " << out_file_name << endl;
		
		while (getline(in_file, line)) {
			index++;
			cout << "Copying Line " << index << endl;
			cout << line << endl;
			out_file << line << endl;
		}

		in_file.close();
		out_file.close();

		cout << "Successfully copied!" << endl;
	}
	else if (!in_file.is_open()) {
		cout << "Error while opening the input file!" << endl;
	}
	else {
		cout << "Error while opening the output file!" << endl;
	}
}
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main() {
	string in_file_name;
	string out_file_name;

	cout << "What is the infile name: ";
	cin >> in_file_name;

	cin.ignore();

	cout << "What is the outfile name: ";
	cin >> out_file_name;

	ofstream out_file(out_file_name, ios::out);
	ifstream in_file(in_file_name, ios::in);
	string line;
	int index = 0;

	if (in_file.is_open() && out_file.is_open()){
		cout << "Opening file " << in_file_name << " and copying contents to " << out_file_name << endl;
		
		while (getline(in_file, line)) {
			index++;
			cout << "Copying Line " << index << endl;
			cout << line << endl;
			out_file << line << endl;
		}

		in_file.close();
		out_file.close();

		cout << "Successfully copied!" << endl;
	}
	else if (!in_file.is_open()) {
		cout << "Error while opening the input file!" << endl;
	}
	else {
		cout << "Error while opening the output file!" << endl;
	}
}