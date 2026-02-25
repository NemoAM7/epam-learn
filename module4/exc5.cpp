#include<iostream>
#include<vector>
using namespace std;

class LogSession {
	int id;
public:
	LogSession(int id) : id(id) {
		printLog("started");
	}

	void printLog(const string& message) {
		cout << "[" << id << "] " << message << endl;
	}

	~LogSession() {
		printLog("ended");
	}
};


void performDataValidation(int data_value) {
	LogSession session3(3);

	if (data_value < 0) throw "Invalid Data";
	session3.printLog("data validated successfully");
}

void processTransactions(const vector<int>& transactions) {
	LogSession session2(2);

	for (int data : transactions) {
		performDataValidation(data);
	}
	session2.printLog("transaction processed");
}

void startCriticalOperation(const vector<int>& transactions) {
	LogSession session1(1);

	processTransactions(transactions);
	session1.printLog("critical operation completed");
}

int main() {
	cout << "Starting the main block" << endl;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(-1);
	v1.push_back(3);
	
	try {
		startCriticalOperation(v1);
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
			
}
