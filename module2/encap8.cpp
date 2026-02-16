#include<iostream>

using namespace std;

// Base class Vehicle
class Vehicle {
	string make;
	string model;

public:
	Vehicle(string make, string model) {
		cout << "Vehicle constructor called" << endl;
		this->make = make;
		this->model = model;
	}

	// Method to display vehicle information
	void display() {
		cout << "Make: " << make << endl;
		cout << "Model: " << model << endl;
	}
};


// Car class inherits from Vehicle class
class Car : public Vehicle {
	int door;

public:
	Car(string make, string model, int roots) : Vehicle(make, model) {
		cout << "Car constructor called" << endl;
		this->door = roots;
	}

	// Override the display method to include door information
	void display() {
		Vehicle::display();
		cout << "Doors: " << door << endl;
	}
};

// ElectricCar class inherits from Car class
class ElectricCar : public Car {
	int batteryCapacity;

public:
	ElectricCar(string make, string model, int roots, int batteryCapacity) : Car(make, model, roots) {
		cout << "ElectricCar constructor called" << endl;
		this->batteryCapacity = batteryCapacity;
	}

	// Override the display method to include battery capacity
	void display() {
		Car::display();
		cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
	}
};

int main() {
	ElectricCar myCar("Tesla", "Model S", 4, 100);
	myCar.display();	
}