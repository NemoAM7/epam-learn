#include<iostream>
using namespace std;

// This class represents a simple bank account with basic functionalities such as deposit, withdraw, and checking balance.
class BankAccount {
	int accountNumber;
	double balance;
public:

	// Constructor to initialize the bank account with an account number and a starting balance of 0.
	BankAccount(int accountNumber) : accountNumber(accountNumber), balance(0) {}

	// Method to deposit money into the account. It checks if the amount is valid (greater than 0) before adding it to the balance.
	void deposit(double amount) {
		if (amount <= 0) {
			cout << "Invalid amount!" << endl;
			return;
		}

		balance += amount;
		cout << "Deposit successful!" << endl;
		cout << "Current balance: " << balance << endl;
	}

	// Method to withdraw money from the account. It checks if the amount is valid and if there are sufficient funds before deducting it from the balance.
	void withdraw(double amount) {
		if (amount <= 0) {
			cout << "Invalid amount!" << endl;
		}
		else if (balance >= amount) {
			balance -= amount;
			cout << "Withdrawal successful!" << endl;
			cout << "Current balance: " << balance << endl;
		}
		else {
			cout << "Insufficient funds!" << endl;
		}
	}

	// Method to get the current balance of the account.
	double getBalance() {
		return balance;
	}
};

int main() {
	// Create a bank account with account number 1234
	BankAccount account(1234);

	// will give error because balance and accountNumber are private members of BankAccount class
	// cout << account.balance << " " << account.accountNumber << endl;

	// Perform a series of transactions on the account, including valid and invalid deposits and withdrawals.
	account.withdraw(-100);
	account.deposit(-10);
	account.deposit(500);
	account.withdraw(600);
	account.withdraw(300);

	// Display the final balance of the account after the transactions.
	cout << "Final balance: " << account.getBalance() << endl;
}
