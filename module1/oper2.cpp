#include<iostream>
#include<string>

/*
* File: GetSimpleInterest.cpp
* Author: Ayaan Mandal
* Created at: 20-01-2026
* Description: A program to calculate simple interest by taking the values of principal amount, rate of interest,
*              currency and the time period from the user.
*/


// Takes float input from user, prints a prompt message before taking the input from user. Returns a float.
float getFloat(std::string message){
  float input_f;
  std::cout << message << ": "; // print the prompt given in parameters and add a seperator.
  std::cin >> input_f;
  return input_f; // return the input value
}


// Takes string input from user, prints a prompt message before taking the input from user. Returns a string.
std::string getString(std::string message){
  std::string input_s;
  std::cout << message << ": "; // print the prompt given in parameters and add a seperator.
  std::cin >> input_s;
  return input_s; // return the input value
}

// Calculates the simple interest by taking the principal, rate of interest and time period in arguments. Returns a float.
float getSimpleInterest(float principal_amount, float rate_of_interest_yearly, float time_period_year){
  return (principal_amount * rate_of_interest_yearly * time_period_year) / 100;
}


int main(){
  std::cout << "Simple Interest Calculator\n";
  
  // uninitalized variables declared for principal amount, rate of interest yearly, time period in years and currency of principal amoumt.
  float principal_amount, rate_of_interest_yearly, time_period_year, simple_interest;
  std::string currency;
  
  // get the curreny from user.
  currency = getString("Please enter your currency (USD/INR)");
  
  
  // Check if currency is in registered currencies.
  if (currency == "USD" or currency == "INR"){
    
    // get the principal, rate of interest and time period from the user.
    principal_amount = getFloat("Please enter the Principal Amount");
    rate_of_interest_yearly = getFloat("Please enter of Rate of Interest Per Annum");
    time_period_year = getFloat("Please enter the Time Period in years");
    
    // calculate the simple interest
    simple_interest = getSimpleInterest(principal_amount, rate_of_interest_yearly, time_period_year);
    
    //print the calculated value
    std::cout << "Your calculated simple interest amount for the principal amount of " << currency << " " << principal_amount
         << " over the period of " << time_period_year << " years with an annualized rate interest of "
         << rate_of_interest_yearly << " % is " << simple_interest << " " << currency << ".\n";
         
    return 0;
  }
  else { 
    // Terminate the program is currency is not valid.
    std::cout << "Invalid Currency.\n";
    
    return 1;
  }
}