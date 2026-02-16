#include<iostream>
using namespace std;

class Device {
public:
	int id;

	void showId() {
		cout << id << endl;
	}
};

class Phone : public virtual Device {
	
};

class Camera : public virtual Device {
	
};

class Smartphone : public Phone, public Camera {

};



int main() {
	Smartphone iphone;
	iphone.id = 10;
	iphone.showId();

	cout << "Via Phone: " << static_cast<Device*>((Phone*)&iphone) << '\n';
	cout << "Via Camera: " << static_cast<Device*>((Camera*)&iphone) << '\n';

}