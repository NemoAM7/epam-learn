#include<iostream>


class LogMessage {
private:
	std::string message_content;
public:
	LogMessage(const std::string& message) : message_content(message) {
		std::cout << "Log Message '" << message_content << "' created. Address: " << this << std::endl;
	}
	~LogMessage() {
		std::cout << "Log Message '" << message_content << "' destroyed. Address: " << this << std::endl;
	}

	void printContent() const {
		std::cout << message_content << std::endl;
	}
};

void handleLegacyLog(LogMessage* rawMessage) {
	std::cout << "Entered handling function" << std::endl;
	if (rawMessage == nullptr) {
		std::cout << "Legacy System recieved a nullptr log\n";
		return;
	}
	std::cout << "Legacy system is now handling log: ";
	rawMessage->printContent();

	delete rawMessage;

	std::cout << "Legacy system has finished processing and deleting the message." << std::endl;
	std::cout << "Exiting handling function" << std::endl;
}

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
	std::unique_ptr<LogMessage> myLog = std::make_unique<LogMessage>("System Startup Event");
	myLog->printContent();
	LogMessage* handedOverLog = myLog.release();
	std::cout << "Ownership released from the unique ptr" << std::endl;

	handleLegacyLog(handedOverLog);
	if (!myLog) {
		std::cout << "myLog unique_ptr is now empty (nullptr) after release(). \n";
	}
	else {
		std::cout << "Error: myLog unique_ptr is NOT empty after release()!\n";
	}

	int rawSensorValue = 75;
	std::string sensorIdentifier = "Pressure_A01";
	std::unique_ptr<SensorReport> criticalReportPtr = std::make_unique<SensorReport>(sensorIdentifier, rawSensorValue);

	std::cout << "\nProcessing critical sensor report: " << std::endl;
	criticalReportPtr->displayDetails();

	// Error: since two unique_ptr cant point the same memory
	// std::unique_ptr<SensorReport> anotherReportPtr = criticalReportPtr;

	std::cout << "Program completed!" << std::endl;
}
