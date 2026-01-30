#include <iostream>
using namespace std;

/*
File : SensorMonitoringSystemInit.cpp
Author : Ayaan Mandal
Created on : 16th January 2026
Description : This program initializes the Sensor Monitoring System for an agricultural farm.
Dependencies : for input/output
*/

int main() {
    // Sensor Type Code ('T' for Temperature, 'H' for Humidity, 'S' for Soil Moisture)
    char sensor_type_code{ 'T' };

    // Unique Sensor ID 
    int sensor_id{ 101 };

    // Temperature Readings in Celsius in Last 5 Hours
    float temperature_readings[5] = { 23.5, 24.0, 22.8, 23.9, 24.1 };

    // Humidity Level in Percentage
    double humidity_level{ 65.5 };

    // System Status (true for active, false for inactive)
    bool system_status{ true };

    // Alert Threshold in Celsius
    const short alert_threshold{ 30 };

    // Total Data Points Collected Since Inception
    long long total_data_points{ 5000 };

    // Maximum Sensors Supported by the System
    unsigned int max_sensors_supported{ 100 };

    // Print the initialized variables
    cout << "Sensor Monitoring System Initialized with following parameters:\n";
    cout << "Sensor Type Code: " << sensor_type_code << "\n";
    cout << "Sensor ID: " << sensor_id << "\n";
    cout << "Temperature Readings (Last 5 Hours): ";

    for (const auto& temp : temperature_readings) {
        cout << temp << " ";
    }

    cout << "\nHumidity Level: " << humidity_level << "%\n";
    cout << "System Status: " << (system_status ? "Active" : "Inactive") << "\n";
    cout << "Alert Threshold: " << alert_threshold << " C\n";
    cout << "Total Data Points Collected: " << total_data_points << "\n";
    cout << "Maximum Sensors Supported: " << max_sensors_supported << "\n";

    return 0;
}