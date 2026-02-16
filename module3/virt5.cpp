#include<iostream>
#include<vector>

using namespace std;

// Payment base class
class Payment {
public:
	virtual void processPayment(double amount) = 0;
};

// Credit Card Payment derived class
class CreditCardPayment : public Payment {
private:
	double debt = 0;
public:
	void processPayment(double amount) override {
		if (amount < 0) {
			cout << "Invalid amount!" << endl;
			return;
		}

		cout << "Processing credit card payment" << endl;
		debt += amount;
		cout << "Account status: " << "Debt: " << debt << endl;
	}
};

// PayPal Payment derived class
class PayPalPayment : public Payment {
private:
	double balance = 1000;
public:
	void processPayment(double amount) override {
		if (amount < 0) {
			cout << "Invalid amount!" << endl;
			return;
		}

		cout << "Processing PayPal payment" << endl;

		if (amount > balance) {
			cout << "Insufficient Funds!" << endl;
			return;
		}

		balance -= amount;
		cout << "Account status: " << "Balance: " << balance << endl;
	}
};

int main() {

	// vector of payment pointers
	vector<Payment*> payments;

	// vector of transaction amounts
	vector<double> transactions;


	// populate the vector with payments simulating an abstract payment stream
	payments.push_back(new CreditCardPayment());
	payments.push_back(new PayPalPayment());
	payments.push_back(new CreditCardPayment());
	payments.push_back(new CreditCardPayment());
	payments.push_back(new PayPalPayment());

	// populate the vector with transactions simulating an abstract payment stream
	transactions.push_back(30);
	transactions.push_back(500);
	transactions.push_back(1000);
	transactions.push_back(2000);
	transactions.push_back(2000);

	// process each payment with the corresponding transaction
	for (int i = 0; i < payments.size(); i++) {
		payments[i]->processPayment(transactions[i]);
		delete payments[i];
	}
}