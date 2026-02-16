#include <iostream>
#include <string> 

using namespace std;

class Messenger {
public:
    // Called when exactly 1 argument is passed
    void send(const string& msg) {
        cout << "[DEFAULT]: " << msg << endl;
    }

    // Called when exactly 2 arguments are passed
    void send(const string& msg, int priority) {
        cout << "[priority level "<< priority << "]: " << msg << endl;
    }
};

int main() {
    Messenger ms;
    ms.send("Hello!");          // Outputs: [DEFAULT]: Hello!
    ms.send("Urgent!", 5);      // Outputs: [priority level 5]: Urgent!
}