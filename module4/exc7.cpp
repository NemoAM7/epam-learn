#include<iostream>
using namespace std;

class BankAccount {
	string owner;
	int accountNumber;
	double balance;
public:
	BankAccount(const string& owner, int accountNumber, double balance) : owner(owner), accountNumber(accountNumber), balance(balance) {
		
	}

	void deposit(double amount) {
		if (amount < 0) {
			throw invalid_argument("Cannot deposit negative amount.");
		}

		balance += amount;
	}

	void withdraw(double amount) {
		if (amount < 0) {
			throw invalid_argument("Cannot withdraw negative amount.");
		}

		if (amount > balance) {
			throw runtime_error("Insufficient funds to proceed the withdrawal.");
		}

		balance -= amount;
	}

	bool transferTo(BankAccount& recipient, double amount) {
		if (amount < 0 || amount > balance) {
			return false;
		}

		recipient.balance += amount;
		balance -= amount;

		return true;
	}

	double getBalance() {
		return balance;
	}

	void print() {
		cout << "Owner: " << owner << endl;
		cout << "Account Number: " << accountNumber << endl;
		cout << "Balance: " << balance << endl;
	}
};


int main() {
	BankAccount alice("Alice", 1001, 500.0);
	BankAccount bob("Bob", 1002, 300.0);
	
	alice.deposit(10);
	alice.print();
	try {
		alice.deposit(-10);
	}
	catch (const exception& e) {
		cout << "Deposit error:" << endl;
		cout << e.what() << endl;
	}
	alice.print();

	alice.withdraw(10);
	alice.print();
	try {
		alice.withdraw(600);
	}
	catch (const exception& e) {
		cout << "Withdraw error:" << endl;
		cout << e.what() << endl;
	}
	alice.print();

	bool status = alice.transferTo(bob, 200);
	cout << "Transfer status: " << status << endl;

	alice.print();
	bob.print();
	
	bool status = alice.transferTo(bob, 600);
	cout << "Transfer status: " << status << endl;

	alice.print();
	bob.print();
}