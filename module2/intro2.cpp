#include<iostream>
using namespace std;

// Base BankAccount class
class BankAccount {

	//private data members
	int accountNumber;
	double balance = 0;

	public:

	//public methods
	BankAccount(int accountNumber) {
		this->accountNumber = accountNumber;
	}

	void deposit(double amount) {
		if (amount <= 0) {
			cout << "Cannot deposit negative amount!" << endl;
			return;
		}
		cout << amount << " amount deposited!" << endl;
		balance += amount;
	}
	
	void withdraw(double amount) {
		if (amount <= 0) {
			cout << "Cannot withdraw negative amount!" << endl;
			return;
		}

		if (amount > balance) {
			cout << "Insufficient funds to withdraw amount" << endl;
			return;
		}

		cout << amount << " amount withdrawn!" << endl;

		balance -= amount;
	}

	double getBalance() {
		return balance;
	}

	protected:

	// protected data members
	string ownerName;
};

// Child VIPAccount, inherits BankAccount class
class VIPAccount : BankAccount {
	public:

	VIPAccount(int accountNumber) : BankAccount(accountNumber) {}
	
	// public methods to access protected data members in base class
	void setOwnerName(string name) {
		ownerName = name;
	}

	string getOwnerName() {
		return ownerName;
	}
};

int main() {
	BankAccount account1(123456);

	// direct access
	// cout << account1.accountNumber << endl; throws error since we are accessing a private class member from outside (main) the class 
	// account1.balance = 20; throws error for same reason

	// getter/setter access (safer)
	// setter usage
	account1.deposit(10); // increases balance by 10
	account1.withdraw(-2); // runs but doesnt update balance (negative values)
	account1.withdraw(20); // runs but doesnt update balance (insufficient balance)
	account1.withdraw(5); // runs and updates the balance
	// getter usage
	cout << "Current Balance: " << account1.getBalance() << endl; // runs and returns the balance

	VIPAccount account2(123457);
	// account1.ownerName = ":)"; throws error since we are trying to access a protected member of a super class
	account2.setOwnerName(":D"); // runs since we are using a child class to access protected members
	cout << "Owner of account: " <<  account2.getOwnerName() << endl;

}