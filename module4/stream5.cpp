#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Book {
	string title;
	string author;
	double price;

public:
	Book(string title, string author, double price) : title(title), author(author), price(price){	}
	Book(){}

	friend ostream& operator<<(ostream& os, const Book& book);
	friend istream& operator>>(istream& is, Book& book);

	friend void saveToFile(const Book& book, ofstream& ofs);
	friend Book loadFromFile(ifstream& ifs);

};

ostream& operator<<(ostream& os, const Book& book) {
	os << "Book( book: " << book.title << ", author: " << book.author << ", price: " << book.price << " )";
	return os;
}

istream& operator>>(istream& is, Book& book) {
	cout << "Name of book: ";
	cin >> book.title;
	cout << "Name of author: ";
	cin >> book.author;
	cout << "Price of book: ";
	cin >> book.price;

	return is;
}

void saveToFile(const Book& book, ofstream& ofs) {
	int title_size = sizeof(*(book.title.c_str()));
	ofs.write((char*)&title_size, sizeof(int));
	ofs.write((char*)book.title.c_str(), title_size);

	int author_size = sizeof(*(book.author.c_str()));
	ofs.write((char*)&author_size, sizeof(int));
	ofs.write((char*)book.author.c_str(), author_size);

	ofs.write((char*)&book.price, sizeof(book.price));
	ofs.close();
}

Book loadFromFile(ifstream& ifs) {
	Book b;
	int title_size, author_size;

	ifs.read((char*)&title_size, sizeof(int));
	ifs.read((char*)&b.title, title_size);

	ifs.read((char*)&author_size, sizeof(int));
	ifs.read((char*)&b.author, author_size);

	ifs.read((char*)&b.price, sizeof(double));
	ifs.close();
	return b;
}



int main() {
	Book* bp = new Book();

	delete bp;
	bp = NULL;
	delete bp;
}