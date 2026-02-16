#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base item clas
class Item {
private:
    string title;
    int id;

public:
    Item(string t, int i) {
        // title validation
        if (!t.empty()) title = t;
        else title = "Untitled";

        // id validation
        if (i > 0) id = i;
        else id = 0;
    }

    virtual ~Item() {}

    string getTitle() const { return title; }
    int getId() const { return id; }

    virtual void display() const = 0;
};

// Derived book class
class Book : public Item {
private:
    int pages;

public:
    Book(string t, int i, int p) : Item(t, i) {
        // Page validation
        if (p > 0) pages = p;
        else pages = 1;
    }

    void setPages(int p) {
        if (p > 0) pages = p;
        else cout << "Invalid pages." << endl;
    }

    void display() const override {
        cout << "Book: " << getTitle() << ", ID: " << getId() << ", Pages: " << pages << endl;
    }
};

// Derived magazine class
class Magazine : public Item {
private:
    int issue;

public:
    Magazine(string t, int i, int iss) : Item(t, i) {
        // issue validation
        if (iss > 0) issue = iss;
        else issue = 1;
    }

    void display() const override {
        cout << "Magazine: " << getTitle() << ", ID: " << getId() << ", Issue: " << issue << endl;
    }
};

// Derived DVD class
class DVD : public Item {
private:
    double duration;

public:
    DVD(string t, int i, double d) : Item(t, i) {
        // duration validation 
        if (d > 0) duration = d;
        else duration = 1.0;
    }

    void display() const override {
        cout << "DVD: " << getTitle() << ", ID: " << getId() << ", Duration: " << duration << endl;
    }
};

int main() {
    // vector of iterm references
    vector<Item*> library;

    // populating the vector
    library.push_back(new Book("Harry potter", 101, 180));
    library.push_back(new Magazine("Vogue", 102, 540));
    library.push_back(new DVD("Beatles", 103, 148.5));

    // displaying each one of them
    for (int i = 0; i < library.size(); i++) {
        library[i]->display();
    }

    // verify input validation
    Book* myBook = new Book("CLRS", 104, 1000);
    myBook->setPages(-50);
    myBook->display();

    return 0;
}