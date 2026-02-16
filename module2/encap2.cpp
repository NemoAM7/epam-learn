#include<iostream>
using namespace std;

// Define a Temperature class with private member variable
class Temperature {
	double celsius;

public:
	
	// Setter method to set temperature in Celsius
	void setCelsius(double temp) {
		if (temp < -273.15) {
			cout << "Temperature cant be below absolute zero (-273.15 C). Set again!" << endl;
		} else {
			celsius = temp;
		}
	}

	// Getter method to get temperature in Celsius
	double getCelsius() const {
		return celsius;
	}

	// Method to convert Celsius to Fahrenheit
	double getFahrenheit() const {
		return celsius * 9 / 5 + 32;
	}	

};


int main() {
	
	// Create an instance of Temperature
	Temperature thermometer;

	//cout << thermometer.celsius << endl; // Error: 'celsius' is private

	thermometer.setCelsius(-300); // Attempt to set below absolute zero
	thermometer.setCelsius(25);   // Set to 25 degrees Celsius
	cout << "Temperature in Celsius: " << thermometer.getCelsius() << " C" << endl;

}