#include <iostream>
using namespace std;

/*
* Program: TemperatureConversion.cpp
* Author: Ayaan Mandal
* Description: Takes float input from user for temperature in fahrenheit and converts it to celsius and prints the converted value.
* Created at: 20-01-2026
*/

// function which takes temperature in fahrenheit in arguments and returns temperature in celsius
float fahrenheitToCelsius(float temp_f){
  return (temp_f - 32) * 5 / 9; //formula to convert F -> C
}

// function which takes temperature in celsius in arguments and returns temperature in fahrenheit
float celsiusToFahrenheit(float temp_c){
  return temp_c * 9 / 5 + 32; //formula to convert C -> F
}

float getFloatInput(){
  float userInput;
  cout << "Please input a real number: " << endl; 
  cin >> userInput; // take input from user and store it in userInput variable
  
  return userInput; // return the input value 
}


int main() 
{
    // uninitalized variable to store temperate in fahrenheit
    float temp_f;
    // uninitalized variable to store temperate in fahrenheit
    float temp_c;
    
    // ask user for the temperature in fahrenheit
    temp_f = getFloatInput();
    
    // convert the fahrenheit temperature to celsius and store it in the tempCelsius variable
    temp_c = fahrenheitToCelsius(temp_f);
    
    // print the temperature data
    cout << "Temperature in Fahrenheit: " << temp_f << endl;
    cout << "Converted Temperature in Celsius: " << temp_c << endl;
    
    return 0;
}