#include<iostream>
using namespace std;
static float g_balance = 0.0;

// Dummy function for pin validation
bool validatePin(int pin) {
	return true;
}

// Deposits positive amount to the global balance
void deposit(float amount){ 
	if (amount <= 0) {
		cout << "Amount should be greater than zero\n";
		return;
	}
	g_balance += amount;
	cout << "Successfully deposited: Rs. " << amount << "\n";
	cout << "Current Balance: Rs. " << g_balance << "\n";
}

// Withdraws positive amount from the global balance if sufficient funs are available
void withdraw(float amount){
	if (amount <= 0) {
		cout << "Amount should be greater than zero\n";
		return;
	}
	if (amount > g_balance) {
		cout << "Insufficient balance\n";
		return;
	}
	g_balance -= amount;
	cout << "Successfully deposited: Rs. " << amount << "\n";
	cout << "Current Balance: Rs. " << g_balance << "\n";
}

// Returns the current balance
float checkBalance() {
	return g_balance;
}

int main() {
	cout << "Banking System\n";

	// Variables for user input and control
	bool loopFlag = true;
	short pin, choice;
	float amount;

	cout << "Enter your pin: ";
	cin >> pin;

	// main loop
	while (loopFlag) {
		cout << "=======================\n";
		cout << "What do you want to do?\n";
		cout << "[1] Deposit\n[2] Withdraw\n[3] Check Balance\nPress any other key to exit\n";
		cin >> choice;

		switch (choice) {

		case 1:
			cout << "Enter amount to deposit: ";
			cin >> amount;
			deposit(amount);
			break;

		case 2:
			cout << "Enter amount to withdraw: ";
			cin >> amount;
			withdraw(amount);
			break;

		case 3:
			cout << "Your balance is: Rs. " << checkBalance() << "\n";
			break;

		default:
			cout << "Thank you for using!\n";
			loopFlag = false;
			break;

		}
	}
}