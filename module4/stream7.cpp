#include<fstream>
#include<iostream>
using namespace std;
int main() {

	ifstream ifs("test.txt", ios::in);

	if (!ifs.is_open()) {
		cout << "Could not open the file." << endl;
		return 1;
	}


	int value;
	while (1) {
		ifs >> value;

		if (ifs.bad()) {
			cout << "Stream is bad exiting..." << endl;
			break;
		}

		if (ifs.eof()) {
			cout << "End of file reached" << endl;
			break;
		}


		if (ifs.fail()) {
			cout << "Invalid character found, ignoring and continuing..." << endl;
			ifs.clear();
			ifs.ignore();
			continue;
		}

		cout << value << endl;

	}
	ifs.close();

	return 0;
}