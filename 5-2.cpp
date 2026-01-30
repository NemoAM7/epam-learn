#include <iostream>
#include <string>

/*
File: GetSimpleInterest.cpp
Author: Ayaan Mandal
Created at: 20-01-2026
Description: A program to calculate simple interest by taking the values of 
             principal amount, rate of interest, currency and the time period from the user.
*/

// Takes float input from user, prints a prompt message before taking the input.
float getFloat(std::string message) {
    float input_f;
    std::cout << message << ": ";
    std::cin >> input_f;
    return input_f;
}

// Takes string input from user, prints a prompt message before taking the input.
std::string getString(std::string message) {
    std::string input_s;
    std::cout << message << ": ";
    std::cin >> input_s;
    return input_s;
}

// Calculates the simple interest using the formula: (P * R * T) / 100
float getSimpleInterest(float principal_amount, float rate_of_interest_yearly, float time_period_year) {
    return (principal_amount * rate_of_interest_yearly * time_period_year) / 100;
}

int main() {
    std::cout << "Simple Interest Calculator\n";

    float principal_amount, rate_of_interest_yearly, time_period_year, simple_interest;
    std::string currency;

    // Get the currency from user
    currency = getString("Please enter your currency (USD/INR)");

    // Check if currency is in registered currencies
    if (currency == "USD" || currency == "INR") {
        // Get inputs from user
        principal_amount = getFloat("Please enter the Principal Amount");
        rate_of_interest_yearly = getFloat("Please enter the Rate of Interest Per Annum");
        time_period_year = getFloat("Please enter the Time Period in years");

        // Calculate simple interest
        simple_interest = getSimpleInterest(principal_amount, rate_of_interest_yearly, time_period_year);

        // Print the results
        std::cout << "Your calculated simple interest amount for the principal amount of " << currency << " " << principal_amount
                  << " over the period of " << time_period_year << " years with an annualized rate interest of "
                  << rate_of_interest_yearly << "% is " << simple_interest << " " << currency << ".\n";
        
        return 0;
    } 
    else {
        // Terminate the program if currency is not valid
        std::cout << "Invalid Currency.\n";
        return 1;
    }
}