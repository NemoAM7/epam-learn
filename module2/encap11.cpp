#include <iostream>
#include <string>

// Base Class: Device
class Device {
public:
    std::string deviceID;

    Device(std::string id) : deviceID(id) {
        std::cout << "Device constructor called for ID: " << deviceID << std::endl;
    }

    virtual ~Device() {}
};

// Intermediate Class: Phone
// Uses virtual inheritance to prevent duplication
class Phone : virtual public Device {
public:
    Phone(std::string id) : Device(id) {
        std::cout << "Phone constructor called." << std::endl;
    }

    void makeCall() {
        std::cout << "Phone " << deviceID << " is making a call..." << std::endl;
    }
};

// Intermediate Class: Camera
// Uses virtual inheritance to prevent duplication
class Camera : virtual public Device {
public:
    Camera(std::string id) : Device(id) {
        std::cout << "Camera constructor called." << std::endl;
    }

    void takePhoto() {
        std::cout << "Camera " << deviceID << " is snapping a photo..." << std::endl;
    }
};

// Most-Derived Class: Smartphone
class Smartphone : public Phone, public Camera {
public:
    // The most-derived class is responsible for 
    // initializing the virtual base class (Device).
    Smartphone(std::string id) : Device(id), Phone(id), Camera(id) {
        std::cout << "Smartphone constructor called." << std::endl;
    }

    void showStatus() {
        std::cout << "\nSmartphone Status - Shared Device ID: " << deviceID << std::endl;
    }
};

int main() {
    Smartphone myPhone("iphone");

    myPhone.makeCall();
    myPhone.takePhoto();
    myPhone.showStatus();

    std::cout << "Address of ID via Phone:  " << (void*)&myPhone.Phone::deviceID << std::endl;
    std::cout << "Address of ID via Camera: " << (void*)&myPhone.Camera::deviceID << std::endl;

    return 0;
}