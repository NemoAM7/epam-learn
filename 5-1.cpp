#include <iostream>
using namespace std;

/*
Program: TemperatureConversion.cpp
Author: Ayaan Mandal
Description: Takes float input from user for temperature in fahrenheit and
             converts it to celsius and prints the converted value.
Created at: 20-01-2026
*/

// Function which takes temperature in fahrenheit and returns temperature in celsius 
float fahrenheitToCelsius(float tempFahrenheit) {
    return (tempFahrenheit - 32) * 5 / 9; // formula to convert F -> C 
}

float takeFloatInput() {
    float userInput;
    cout << "Please input a real number: " << endl;
    cin >> userInput; // take input from user and store it in userInput variable
    return userInput; // return the input value 
}

int main() {
    // Uninitialized variables to store temperature in fahrenheit and celsius 
    float tempFahrenheit;
    float tempCelsius;

    // Ask user for the temperature in fahrenheit
    tempFahrenheit = takeFloatInput();

    // Convert the fahrenheit temperature to celsius and store it in the tempCelsius variable
    tempCelsius = fahrenheitToCelsius(tempFahrenheit);

    // Print the temperature data
    cout << "Temperature in Fahrenheit: " << tempFahrenheit << endl;
    cout << "Converted Temperature in Celsius: " << tempCelsius << endl;

    return 0;
}