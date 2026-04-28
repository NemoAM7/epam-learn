#include<iostream>
#include<map>
#include<limits>
using namespace std;

void clearInputBuffer() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool getProductStock(int productId, int& currentStock, const std::map<int, int>& inventoryMap) {
	if (inventoryMap.find(productId) == inventoryMap.end()) {
		currentStock = 0; return false;
	}
	else {
		currentStock = inventoryMap.at(productId); return true;
	}
}

void displayInventory(const std::map<int, int>& inventoryMap, const string& title) {
	cout << title << endl;
	cout << "ID \t | Stock" << endl;
	cout << "--------------------" << endl;
	for (const auto& [productId, stockQuantity] : inventoryMap) {
		cout << productId << " \t | " << stockQuantity << endl;
	}
}

void addNewProduct(std::map<int, int>& inventoryMap) {
	int productId;
	cout << "Enter Product ID: "; cin >> productId;
	if (cin.fail()) {
		clearInputBuffer();
		return;
	}
	if (inventoryMap.find(productId) != inventoryMap.end()) {
		cout << "Product ID already exists!" << endl;
		return;
	}
	int stockQuantity = 0;
	cout << "Enter Stock Quantity: "; cin >> stockQuantity;
	if (cin.fail()) {
		clearInputBuffer();
		return;
	}
	if (stockQuantity <= 0) {
		cout << "Stock Quantity cannot be non-postive! Setting to zero" << endl;
	}
	inventoryMap[productId] = stockQuantity;
	cout << "Succesfully added the product!" << endl;
}

void performSale(std::map<int, int>& inventoryMap) {
	int productId;
	cout << "Enter Product ID: "; cin >> productId;
	if (cin.fail()) {
		clearInputBuffer();
		return;
	}
	if (inventoryMap.find(productId) == inventoryMap.end()) {
		cout << "Product ID doesnt exist!" << endl;
		return;
	}
	int sellingQuantity;
	cout << "Enter Selling Quantity: "; cin >> sellingQuantity;
	if (cin.fail()) {
		clearInputBuffer();
		return;
	}
	if (sellingQuantity < 0 || sellingQuantity > inventoryMap.at(productId)) {
		cout << "Selling Quantity cannot be negative and should not exceed the Current Stock Quantity!" << endl;
		return;
	}
	inventoryMap[productId] -= sellingQuantity;
	cout << "Succesfully performed the sale!" << endl;
}

void performRestock(std::map<int, int>& inventoryMap) {
	int productId;
	cout << "Enter Product ID: "; cin >> productId;
	if (cin.fail()) {
		clearInputBuffer();
		return;
	}

	int restockQuantity;
	cout << "Enter Re-stock Quantity: "; cin >> restockQuantity;
	if (cin.fail()) {
		clearInputBuffer();
		return;
	}
	if (restockQuantity <= 0) {
		cout << "Re-stock Quantity cannot be non-positive!" << endl;
		return;
	}

	if (inventoryMap.find(productId) == inventoryMap.end()) {
		cout << "Product doesnt exist, thus adding the product in the inventory!" << endl;
		inventoryMap[productId] = 0;
	}

	inventoryMap[productId] += restockQuantity;
	cout << "Succesfully performed the restock!" << endl;
}

void checkProductStatus(const std::map<int, int>& inventoryMap) {
	int productId;
	cout << "Enter Product ID: "; cin >> productId;
	if (cin.fail()) {
		clearInputBuffer();
		return;
	}

	int currentStock;
	bool status = getProductStock(productId, currentStock, inventoryMap);

	if (status == false) cout << "Product doesnt exist!" << endl;
	else cout << "Product found! Current stock: " << currentStock << endl;
}

void discontinueProduct(std::map<int, int>& inventoryMap) {
	int productId;
	cout << "Enter Product ID: "; cin >> productId;
	if (cin.fail()) {
		clearInputBuffer();
		return;
	}
	if (inventoryMap.find(productId) == inventoryMap.end()) {
		cout << "Product ID doesnt exist choose another!" << endl;
		return;
	}
	inventoryMap.erase(inventoryMap.find(productId));
	cout << "Succesfully discontinued the product!" << endl;
}

void ActionToPerform(std::map<int, int>& inventory) {
	int resp;
	std::string message = "Select operation\n[0] exit\n[1] display inventory\n[2] add a new product\n[3] perform a sale\n[4] perform a restock\n[5] check status of a product\n[6] discontinue a product\nOperation: ";

	do {
		cout << message; cin >> resp;
		clearInputBuffer();
		switch (resp) {
		case 0:
			cout << "Exiting Gracefully..." << endl;
			break;
		case 1:
			displayInventory(inventory, "Current Inventory Overview");
			break;
		case 2:
			addNewProduct(inventory);
			break;
		case 3:
			performSale(inventory);
			break;
		case 4:
			performRestock(inventory);
			break;
		case 5:
			checkProductStatus(inventory);
			break;
		case 6:
			discontinueProduct(inventory);
			break;
		default:
			cout << "Invalid operation!" << endl;
			break;
		}
	} while (resp != 0);

}


int main() {
	std::map<int, int> inventory = { {101, 50},
		{102, 25}, {103, 100}, {104, 10}, {105,75} };

	ActionToPerform(inventory);
}