#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Variable declarations for weight, shipping cost and shipping zone
    int weight;
    char shipping_zone;
    float shipping_cost;

    // Get weight of package from user
    cout << "Enter the order weight in kg: ";
    cin >> weight;

    // Validate weight input
    if (weight < 0 || weight > 100) {
        cout << "Order weight must be positive and less than equal to 100 kg." << endl;
        return 1;
    }

    // Get shipping zone from user
    cout << "Enter the shipping zone (A, B or C): ";
    cin >> shipping_zone;

    // Calculate shipping cost based on weight and shipping zone
    switch (shipping_zone) {
    case 'A':
        if (weight <= 2) {
            shipping_cost = 100;
        }
        else if (weight <= 10) {
            shipping_cost = 200;
        }
        else {
            shipping_cost = 200 + 50 * (weight - 10);
        }
        break;

    case 'B':
        if (weight <= 5) {
            shipping_cost = 300;
        }
        else {
            shipping_cost = 300 + 50 * (weight - 5);
        }
        break;

    case 'C':
        if (weight <= 5) {
            shipping_cost = 500;
        }
        else {
            shipping_cost = 500 + 100 * (weight - 5);
        }
        break;

    default:
        cout << "Invalid Shipping Zone! Please enter (A, B or C).\n";
        return 1;
    }

    // Display the total shipping cost
    cout << "The total shipping cost for " << weight << " kg, for the shipping region "
        << shipping_zone << " is: Rs. " << setprecision(2) << fixed << shipping_cost << ".\n";

    return 0;
}