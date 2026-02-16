#include<iostream>
using namespace std;

class Device {
public:
	int id;

	void showId() {
		cout << id << endl;
	}
};

class Phone : public Device {
	
};

class Camera : public Device {
	
};

class Smartphone : public Phone, public Camera {

};



int main() {
	Smartphone iphone;

	////iphone.id = 101; // ambiguous due to diamond inheritance if not virtually inherited
	////iphone.showId(); // ambiguous due to diamond inheritance if not virutally inherited

	iphone.Phone::id = 20; // scope resolution to specify the class access
	iphone.Camera::showId(); // scope resolution to specify the class access

}