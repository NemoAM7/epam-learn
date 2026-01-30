#include <iostream>
using namespace std;

int main() {

    // variables declared to store input and results
    int inputDays, years, weeks, days;

    cout << "Days to Year, Weeks, and Days Converter" << "\n";
    cout << "Enter the number of days: ";  
    cin >> inputDays;        //Get number of days from user

    years = inputDays / 365; // convert days to years
    days = inputDays % 365;  // remaining days after converting to years 
    weeks = days / 7;		 // convert remaining days to weeks
    days = days % 7;         // remaining days after converting to weeks

    // Display the results
    cout << inputDays << " days is approximately, "
        << years << " years, "
        << weeks << " weeks, and "
        << days << " days." << "\n";

    return 0;
}