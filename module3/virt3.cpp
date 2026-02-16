#include<iostream>
using namespace std;

class Device {
protected:
    int id;
public:
    Device(int id) : id(id) {
        cout << "Device with ID " << id << " constructed!" << endl;
    }

    void showId() {
        cout << id << endl;
    }
};

class Phone : public virtual Device {
public:
    Phone(int id) : Device(id) {
        cout << "Phone with ID " << id << " constructed!" << endl;
    }
};

class Camera : public virtual Device {
public:
    Camera(int id) : Device(id) {
        cout << "Camera with ID " << id << " constructed!" << endl;
    }
};

class Smartphone : public Phone, public Camera {
public:
    Smartphone(int id) : Device(id), Phone(id), Camera(id) {
        cout << "Smartphone with ID " << id << " constructed!" << endl;
    }
};

int main() {
    Smartphone iphone(20);
    iphone.showId();
}