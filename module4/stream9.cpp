#include<iostream>
#include<fstream>
#include<iomanip>
#include<sstream>
#include<chrono>
using namespace std;

class Logger {
	ofstream logFile;
public:
	Logger(string filename) {
		logFile = ofstream(filename, ios::app);
		if (!logFile.is_open()) {
			cout << "Could not open the log file!" << endl;
		}
	}

	void log(const string& message) {
		auto now = chrono::system_clock::now();
	    time_t now_time_t = chrono::system_clock::to_time_t(now);

		tm bt = *localtime(&now_time_t);
		ostringstream oss;
		oss << put_time(&bt, "%Y-%m-%d %H:%M:%S");
		string s = "[" + oss.str() + "]" + message;
		logFile << s << endl;
	}
};

int main() {
	Logger logger("uwu.txt");

	logger.log("a");
	logger.log("b");
	logger.log("c");
	logger.log("d");
	logger.log("e");

}