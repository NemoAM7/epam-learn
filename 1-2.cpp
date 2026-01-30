#include <stdio.h>

/*
File        : EnvironmentalDataLogger.c
Author      : Ayaan Mandal
Created on  : 16th January 2026
Description : This program initializes various variables to log environmental data
Dependencies: <stdio.h> for input/output 
*/

int main() { 
    // Geographical region of sensor (N: North, S: South, E: East, W: West) 
    char sensor_region_code = 'N';

    // Unique identifier for the current sensor reading
    int current_reading_id = 1001;

    // Average soil moisture percentage of farm from the sensor
    float average_soil_moisture = 23.5f;

    // Light intensity on crops in lux from the sensor
    double light_intensity_lux = 4567.89;

    // Temperature of atmosphere in Celsius from the sensor
    short temperature_celsius = 25;

    // Total number of reading collected since the device has been started
    long total_readings_since_start = 150000L;

    // Threshold data value (in Bytes) sent to server to trigger an alert
    unsigned int threshold_data_to_send = 50000U;

    // Flag to indicate if the sensor is in active mode (0x01 for active, 0x00 for idle)
    unsigned char sensor_mode_flag = 0x01;

    // Print the initialized variables
    printf("Environmental Data Logger Initialized with following parameters:\n");
    printf("Sensor Region : %c\n", sensor_region_code);
    printf("Current Reading ID : %d\n", current_reading_id);
    printf("Average Soil Moisture : %.2f%%\n", average_soil_moisture);
    printf("Light Intensity (lux) : %.2f\n", light_intensity_lux);
    printf("Temperature (Celsius) : %d\n", temperature_celsius);
    printf("Total Readings Since Start Of Device: %ld\n", total_readings_since_start);
    printf("Threshold Data To Send (Bytes) : %u\n", threshold_data_to_send);
    printf("Sensor Mode Flag : 0x%02X\n", sensor_mode_flag);

    return 0;
}