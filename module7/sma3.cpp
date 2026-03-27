#include<iostream>
#include<memory>

class SensorReport
{
public:
	SensorReport(const std::string& sensorName, int sensorValue) : sensorName(sensorName), sensorValue(sensorValue) {
		std::cout << "Sensor report for " << sensorName << " created." << std::endl;
	}

	~SensorReport() {
		std::cout << "Sensor report for " << sensorName << " destroyed." << std::endl;
	}

	void displayDetails() const {
		std::cout << "[" << sensorName << "]: value = " << sensorValue << std::endl;
	}


private:
	int sensorValue;
	std::string sensorName;

};


int main() {
	int rawSensorValue = 75;
	std::string sensorIdentifier = "Pressure_A01";
	std::unique_ptr<SensorReport> criticalReportPtr = std::make_unique<SensorReport>(sensorIdentifier, rawSensorValue);

	std::cout << "\nProcessing critical sensor report: " << std::endl;
	criticalReportPtr->displayDetails();

	// Error: since two unique_ptr cant point the same memory
	// std::unique_ptr<SensorReport> anotherReportPtr = criticalReportPtr;

	std::cout << "Program completed!" << std::endl;
}