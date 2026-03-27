#include<iostream>
#include<string>
#include<vector>
#include<memory>

class Book {
public:
    std::string title;
    std::string author;

    Book(const std::string& t, const std::string& a) : title(t), author(a) {}
    void print() const {
        std::cout << "Book: " << title << " by " << author << std::endl;
    }
};

class Library {
    std::vector<std::unique_ptr<Book>> books;  // Change to unique_ptr
public:
    void addBook(const std::string& title, const std::string& author) {
        books.push_back(std::make_unique<Book>(title, author));  // Use make_unique
    }

    Book* findBook(const std::string& title) {  // Return raw pointer for observation
        for (const auto& book : books) {
            if (book->title == title) return book.get();
        }
        return nullptr;
    }

    void removeBook(const std::string& title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if ((*it)->title == title) {
                books.erase(it);  // unique_ptr automatically deletes
                return;
            }
        }
    }
};

int main() {
    Library lib;
    lib.addBook("1984", "George Orwell");

    Book* bookPtr = lib.findBook("1984");
    if (bookPtr) bookPtr->print();

    lib.removeBook("1984");
    bookPtr = nullptr;  // Best practice: set to nullptr after removal

    return 0;
}
