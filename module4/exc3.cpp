#include<iostream>
#include<vector>
#include<limits>

using namespace std;

class InvalidPriceException : public runtime_error {

public:
	InvalidPriceException(const char* msg) : runtime_error(msg) {

	}

	InvalidPriceException(const string& msg) : runtime_error(msg) {

	}
};

class Product {
	string name;
	double price;
	int stock;
public:
	Product(const string& name, const double price, const int stock) : name(name), price(price), stock(stock) {

	}

	string getName() const { return name; }

	double getPrice() const { return price; }

	int getStock() const { return stock; }

	void setPrice(double price) {
		this->price = price;
	}

	void display() const {
		cout << "Name : " << name << endl;
		cout << "Price : " << price << endl;
		cout << "Stock : " << stock << endl;
	}
};

double getNewPrice(const Product& product) {
	double newPrice;
	cout << "Enter the new price (must be a positive number (0,10000]: ";
	cin >> newPrice;

	if (cin.fail()) {
		throw InvalidPriceException("Error: Invalid product selection.");
	}

	if (newPrice <= numeric_limits<unsigned int>::min()) {
		throw InvalidPriceException("Error: Price must be positive.");
	}

	if (newPrice > 10000) {
		throw InvalidPriceException("Error: Price cant go above the set threshold (10000).");
	}

	if (newPrice > product.getPrice() * 1.5) {
		throw InvalidPriceException("Error: Price must not exceed the last price by 50%");
	}

	if (newPrice != round(newPrice * 100) / 100) {
		throw InvalidPriceException("Error: Price must not go above 2 decimal places.");
	}

	cin.clear();
	cin.ignore();

	return newPrice;
}

void updateProductPrice(Product& product) {

	double newPrice;

	while (1) {
		try {
			newPrice = getNewPrice(product);
		}
		catch (InvalidPriceException e) {
			cout << "Error while setting the new price!" << endl;
			cout << e.what() << endl;
			cout << "Please try again!" << endl;
			continue;
		}
		break;
	}

	product.setPrice(newPrice);
	cout << "Product price changed succesfully!" << endl;
	cout << endl;

}

void displayInventory(const vector<Product> products) {
	cout << "All available products are listed below: " << endl;
	for (int i = 0; i < products.size(); i++) {
		cout << "Product-" << i + 1 << endl;
		products[i].display();
		cout << endl;
	}
}

int main() {
	vector<Product> products;

	products.push_back(Product("apple", 20.4, 34));
	products.push_back(Product("banana", 10.2, 23));
	products.push_back(Product("strawberry", 50.15, 16));

	char continueUpdate = 'Y';
	int index;

	cout << "Welcome to product management system." << endl;
	displayInventory(products);

	do{
		try {
			
			while (1) {
				cout << "Select the index of product (1-indexed) : ";
				cin >> index;
				if (1 <= index && index <= products.size()) break;
				cout << "Not a valid index! try again.." << endl;

				cin.clear();
				cin.ignore();
			}
			updateProductPrice(products[index-1]);
			
			displayInventory(products);
		
			cout << "Continue? (Y/N): ";
			cin >> continueUpdate;
		}
		catch (const InvalidPriceException& e) {
			cout << "Error while updating the price for the product, please try again!" << endl;
		}
	} while (continueUpdate == 'y' || continueUpdate == 'Y');
}
