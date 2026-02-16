#include <iostream>
using namespace std;


// This is a simple Car class that simulates basic car operations such as starting, accelerating, braking, and stopping. The class maintains the state of the engine, speed, and RPM. The main function demonstrates how to use the Car class to perform various operations on the car object.
class Car {
private:
	bool engineOn;
	int speed;
	int rpm;
public:
	// Constructor initializes the car's state
	Car() :engineOn(false), speed(0), rpm(0) {}

	// Method to start the car, which sets the engine on and initializes speed and RPM
	void start() {
		engineOn = true;
		rpm = 1000;
		speed = 10;
		cout << "Engine is on, car is moving at " << speed << " km/h with " << rpm << " rpm." << endl;
	}

	// Method to accelerate the car, which increases speed and RPM if the engine is on and speed is below 150 km/h
	void accelerate() {
		if (engineOn && speed < 150) {
			speed += 10;
			rpm += 1000;
			cout << "Accelerating... Current speed: " << speed << " km/h, RPM: " << rpm << endl;
		}
		else if (engineOn) {
			cout << "Max speeed reached!" << endl;
		}
		else {
			cout << "Start the engine first!" << endl;
		}
	}
	
	//	Method to brake the car, which decreases speed and RPM if the speed is above 0
	void brake() {
		if (speed > 0) {
			speed -= 10;
			rpm -= 1000;
			cout << "Braking... Current speed: " << speed << " km/h, RPM: " << rpm << endl;
		}
		else {
			cout << "Car is already stopped!" << endl;
		}
	}
	//	Method to stop the car, which turns off the engine and brings the speed to 0 by braking until the car is stopped
	void stop() {
		if (speed == 0) {
			cout << "Car is already stopped!" << endl;
			return;
		}
		engineOn = false;
		cout << "Engine is off, car is stopping." << endl;
		while (speed > 0){
			brake();
		}
	}
};


int main() {
	// Create an instance of the Car class
	Car myCar;

	myCar.accelerate();
	myCar.start();
	myCar.accelerate();
	myCar.accelerate();
	myCar.brake();
	myCar.accelerate();
	myCar.stop();
	myCar.brake();
	myCar.stop();
}


