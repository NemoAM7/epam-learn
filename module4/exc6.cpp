#include<iostream>
using namespace std;

class MedicalMemoryTracker {
	static int totalMemAllocated;
	static int totalMemDeallocated;
public:


	static void recordAllocation(const char* medicalResource, int size) {
		cout << "Allocated " << size << " bytes to " << medicalResource << endl;
		totalMemAllocated += size;
	}

	static void recordDeallocation(const char* medicalResource, int size) {
		cout << "Deallocated " << size << " bytes from " << medicalResource << endl;
		totalMemDeallocated += size;
	}

	static int reportLeaks() {
		return totalMemAllocated - totalMemDeallocated;
	}

	static void reset() {
		totalMemAllocated = totalMemDeallocated = 0;
	}
};

class MedicalDeviceException : public runtime_error {
public:
	MedicalDeviceException(const string& message) : runtime_error(message) {}
};


class PatientDataException : public runtime_error {
public:
	PatientDataException(const string& message) : runtime_error(message) {}
};

class PatientVitalMonitor {
	int* heartRateData;
	float* bloodPressureData;
	bool deviceConnected;
	char* patientId;

public:
	PatientVitalMonitor(char* patientId) : heartRateData(nullptr), bloodPressureData(nullptr), deviceConnected(false), patientId(patientId) {
		MedicalMemoryTracker::recordAllocation("Heart rate buffer", 36000 * sizeof(int));
		MedicalMemoryTracker::recordAllocation("Blood pressure buffer", 36000 * sizeof(float));
		heartRateData = new int[36000];
		bloodPressureData = new float[36000];

		connectToMedicalDevice();
		calibrateSensors();
	}

	void connectToMedicalDevice() {
		cout << "Attempting to connect to medical device.." << endl;
		if (rand() % 2 == 0) {
			throw MedicalDeviceException("E400: Failure to connect to the medical device.");
		}
		deviceConnected = true;
		cout << "Succesfully connected to the medical device." << endl;
	}

	void calibrateSensors() {
		cout << "Attempting to calibrate the sensors.." << endl;
		if (rand() % 2 == 0) {
			throw MedicalDeviceException("E320: Failure to calibrate the sensors.");
		}
	}

	void validatePatientData() {
		cout << "Attempting to validate patient data.." << endl;
		if (rand() % 2 == 0) {
			throw PatientDataException("E102: Failure to validate patient data.");
		}
		cout << "Succesfully validated patient data." << endl;
	}

	void analyzeCriticalTrend() {
		cout << "Analyzing critical trends.." << endl;
		if (rand() % 2 == 0) {
			throw PatientDataException("E213: Failure to analyze the critical trends.");
		}
		cout << "Succesfully analyzed the criticla trends." << endl;
	}

	void monitorPatientVitals(int duration) {
		if (duration <= 0) {
			throw runtime_error("Monitoring duration must be positive.");
		}

		for (int i = 0; i < duration; i++) {
			float* ecgAnalysisBuffer = new float[5000];
			MedicalMemoryTracker::recordAllocation("ECG analysis buffer", 5000 * sizeof(float));
			validatePatientData();

			float* criticalTrendBuffer = new float[1000];
			MedicalMemoryTracker::recordAllocation("Critical Trend Buffer", 1000 * sizeof(int));
			analyzeCriticalTrend();

			delete[] ecgAnalysisBuffer;
			MedicalMemoryTracker::recordDeallocation("ECG Analysis Buffer", 5000 * sizeof(float));

			delete[] criticalTrendBuffer;
			MedicalMemoryTracker::recordDeallocation("Critical Trend Buffer", 1000 * sizeof(int));
		}

	}

	~PatientVitalMonitor() {
		if (heartRateData != nullptr) {
			MedicalMemoryTracker::recordDeallocation("Heart rate buffer", 36000 * sizeof(int));
			delete[] heartRateData;
			heartRateData = nullptr;
		}

		if (bloodPressureData != nullptr) {
			MedicalMemoryTracker::recordDeallocation("Blood pressure buffer", 36000 * sizeof(float));
			delete[] bloodPressureData;
			bloodPressureData = nullptr;
		}

	}
};


int MedicalMemoryTracker::totalMemAllocated = 0;
int MedicalMemoryTracker::totalMemDeallocated = 0;


int main() {
	cout << "Patient vital monitor with memory leak tracking" << endl;
	srand(static_cast<unsigned>(time(nullptr)));

	int numAttempts;

	cout << "Number of attempts" << endl;
	cin >> numAttempts;

	MedicalMemoryTracker::reset();

	PatientVitalMonitor* emergencyMonitor = nullptr;

	bool setupSuccesful = false;

	while (numAttempts--) {
		try {
			emergencyMonitor = new PatientVitalMonitor("EMERGENCY-101");

			setupSuccesful = true;

			cout << "Succesfully setup the monitor." << endl;
		}
		catch (const MedicalDeviceException& e) {
			cout << e.what() << endl;
			continue;
		}

		try {
			emergencyMonitor->monitorPatientVitals(10);
		}
		catch (const PatientDataException& e) {
			cout << e.what() << endl;
			continue;
		}

		delete emergencyMonitor;
		emergencyMonitor = nullptr;
	}
}