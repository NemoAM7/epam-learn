#include<iostream>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

static unordered_set<string> users;

class InsufficientFundsException : public runtime_error{
	string accountNumber;
	double currentBalance;
	double requestedAmount;
	string msg;
public:
	InsufficientFundsException(const string& account, double balance, double amount) : runtime_error("Insufficient funds!"), accountNumber(account), currentBalance(balance), requestedAmount(amount) {
		ostringstream oss;
		oss << "Insufficient funds to process the transaction!" << endl;
		oss << "Account Number: " << accountNumber << endl;
		oss << "Current Balance: " << currentBalance << endl;
		oss << "Request Amount: " << requestedAmount;
		msg = oss.str();
	}
	
	virtual const char* what() const noexcept override {
		return msg.c_str();
	}

};

class InvalidAmountException: public invalid_argument{
	double balance;
	string operation;
	string msg;
public:
	InvalidAmountException(double balance, const string& operation) : invalid_argument("Invalid Amount!"), balance(balance), operation(operation) {
		ostringstream oss;
		oss << "Operation was invalid!" << endl;
		oss << "Balance: " << balance << endl;
		oss << "Operation: " << operation;
		msg = oss.str();
	}

	virtual const char* what() const noexcept override {
		return msg.c_str();
	}
};

class AccountNotFoundException: public out_of_range{
	string accountNumber;
	string msg;
public:
	AccountNotFoundException(const string& accountNumber) : out_of_range("Account not found!"), accountNumber(accountNumber) {
		ostringstream oss;
		oss << "Account not found!" << endl;
		oss << "Account Number: " << accountNumber;
		msg = oss.str();
	}

	virtual const char* what() const noexcept override {
		return msg.c_str();
	}
};

class TransactionLimitExceededException: public logic_error{
	double amount;
	double limit;
	string msg;
public:
	TransactionLimitExceededException(double amount, double limit) : logic_error("Account not found!"), amount(amount), limit(limit) {
		ostringstream oss;
		oss << "Exceeded the daily transaction limit for today!" << endl;
		oss << "Attempted amount: " << amount << endl;
		oss << "Transaction daily limit: " << limit;
		msg = oss.str();
	}

	virtual const char* what() const noexcept override {
		return msg.c_str();
	}
};

class BankSystemException: public runtime_error{
	string component;
	string error;
	string msg;
public:
	BankSystemException(const string& component, const string& error) : runtime_error("Bank System error!"), component(component), error(error) {
		ostringstream oss;
		oss << "Error with the Bank system!" << endl;
		oss << "Component: " << component << endl;
		oss << "Error: " << error;
		msg = oss.str();
	}

	virtual const char* what() const noexcept override {
		return msg.c_str();
	}
};

class BankAccount {
	string accountNumber;
	string holderName;
	double balance;
	double dailyWithdrawalLimit;
	double dailyWithdrawnAmount;
	bool _isInitialized = false;

	void validateAmount(const double amount, const string& operation) const {
		if (amount <= 0) {
			throw InvalidAmountException(balance, "Amount is not a positive real number!"); 
		}
		if (isnan(amount) || isinf(amount)) {
			throw invalid_argument("Amount is not a valid positive real number!");
		}
	}

public:
	BankAccount() {}

	BankAccount(string accountNumber, string holderName, double balance, double dailyWithdrawalLimit, double dailyWithdrawnAmount) {
		cout << endl << "Attempting to create a bank account!" << endl;
		if (users.find(accountNumber) != users.end()) throw logic_error("Account already exists!");
		users.insert(accountNumber);
		
		//cout << "Balance: " << balance;

		if (balance < 0) {
			throw InvalidAmountException(0, "Balance cannot be a negative real number!");
		}
		
		if (holderName.size() == 0 || accountNumber.size() == 0) {
			throw invalid_argument("Either the holderName or accountNumber or both are left empty! Please recheck the entries!");
		}
		cout << "Bank Account created: " << accountNumber << endl;
		this->accountNumber = accountNumber;
		this->holderName = holderName;
		this->balance = balance;
		this->dailyWithdrawalLimit = dailyWithdrawalLimit;
		this->dailyWithdrawnAmount = dailyWithdrawnAmount;	
		this->_isInitialized = true;
	}

	string getAccountNumber() { return accountNumber; }
	string getHolderName() { return holderName; }
	double getBalance() { return balance; }
	double getDailyWithdrawalLimit() { return dailyWithdrawalLimit; }
	double getDailyWithdrawnAmount() { return dailyWithdrawnAmount; }

	void deposit(double amount) {
		cout << endl << "Attempting to deposit to account!" << endl;

		validateAmount(amount, "Deposit");
		if (amount > 1000000) {
			throw BankSystemException("Deposit", "Fund is too large for single deposit!");
		}

		cout << "Deposit, to:  " << accountNumber << ", amount: " << amount << endl;
		balance += amount; 
	}
	
	void withdraw(double amount) {
		cout << endl << "Attempting to withdraw from account!" << endl;

		validateAmount(amount, "Withdraw");
			
		if (amount > 100000) {
			throw BankSystemException("Withdrawal", "Fraud detected, large withdrawal amount attempted!");
		}

		if (amount > balance) {
			throw InsufficientFundsException(accountNumber, balance, amount);
		}

		if (dailyWithdrawnAmount + amount > dailyWithdrawalLimit) {
			throw TransactionLimitExceededException(dailyWithdrawnAmount + amount, dailyWithdrawalLimit);
		}

		cout << "Withdraw, from:  " << accountNumber << ", amount: " << amount << endl;

		balance -= amount;
		dailyWithdrawalLimit += amount;
	}

	void transferTo(BankAccount& recipient, double amount) {
		cout << endl << "Attempting to transfer to different account!" << endl;

		validateAmount(amount, "transfer");

		if (!recipient._isInitialized) throw AccountNotFoundException(accountNumber);
			
		if (recipient.accountNumber == accountNumber) {
			throw logic_error("Cannot transfer money to yourself!");
		}

		if (amount > balance) {
			throw InsufficientFundsException(accountNumber, balance, amount);
		}

		withdraw(amount);
		try {
			recipient.deposit(amount);
		}
		catch(const exception& e){
			cout << "Exception thrown while attempting to deposit amount, rolling back the amount" << endl;
			balance += amount;
		}
	}

	void printAccountInfo() {
		cout << endl << "Bank Account Details" << endl;
		cout << "Name: " << holderName << endl;
		cout << "Account number: " << accountNumber << endl;
		cout << "Balance: " << balance << endl;
		cout << "Daily Withdrawal Limit: " << dailyWithdrawalLimit << endl;
		cout << "Daily Withdrawn Amount: " << dailyWithdrawnAmount << endl; 
	}
};

template <typename Func>
void protect(Func atomic_logic) {
	try {
		atomic_logic();
	}
	catch (const InsufficientFundsException& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const InvalidAmountException& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const AccountNotFoundException& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const TransactionLimitExceededException& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const BankSystemException& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const std::out_of_range& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const std::invalid_argument& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const std::logic_error& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const std::runtime_error& e) {
		cout << "Error: " << e.what() << endl;
	}
	catch (const std::exception& e) {
		cout << "Error: " << e.what() << endl;
	}
}


int main() {
	BankAccount b1, b2, b3, b4;

	protect([&](){
		b1 = BankAccount("1", "A", 100, 5000, 0);
		b2 = BankAccount("2", "B", 75, 5000, 0);
	});

	b1.printAccountInfo();
	b2.printAccountInfo();

	protect([&]() {
		b1.deposit(20);
		b2.withdraw(25);
		b1.transferTo(b2, 40);
	});

	protect([&]() {
		b3 = BankAccount("1", "A", 100, 5000, 0);
	});

	protect([&]() {
		b2.withdraw(200);
	});

	protect([&]() {
		b4 = BankAccount("3", "C", -1, 5000, 0);
	});

	protect([&]() {
		b1.transferTo(b3, 10);
	});

	protect([&]() {
		b1.deposit(5000);
		b1.withdraw(5000);
	});

	protect([&]() {
		b1.deposit(10000000);
	});
	
	protect([&]() {
		b3 = BankAccount("abcd", "", 0, 5000, 0);
		b1.transferTo(b1, 1);
	});

	protect([&]() {
		b1.deposit(100001);
		b1.withdraw(100001);
	});
}
