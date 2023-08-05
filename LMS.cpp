#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class to represent a book
class Book {
public:
    string title;
    string author;
    int id;
    bool isAvailable;

    Book(string title, string author, int id)
        : title(title), author(author), id(id), isAvailable(true) {}

    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ID: " << id << endl;
        cout << "Status: " << (isAvailable ? "Available" : "Not Available") << endl;
        cout << "---------------------------\n";
    }
};

// Library class to manage the books
class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayAllBooks() {
        cout << "Library Catalog:\n";
        cout << "---------------------------\n";
        for (const auto& book : books) {
            book.displayInfo();
        }
    }

    Book* findBookById(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                return &book;
            }
        }
        return nullptr;
    }

    void borrowBook(int id) {
        Book* book = findBookById(id);
        if (book && book->isAvailable) {
            book->isAvailable = false;
            cout << "You have borrowed the book: " << book->title << endl;
        } else {
            cout << "Book not found or already borrowed.\n";
        }
    }

    void returnBook(int id) {
        Book* book = findBookById(id);
        if (book && !book->isAvailable) {
            book->isAvailable = true;
            cout << "You have returned the book: " << book->title << endl;
        } else {
            cout << "Book not found or already returned.\n";
        }
    }
};

int main() {
    Library library;

    // Adding some books to the library
    library.addBook(Book("Book 1", "Author 1", 101));
    library.addBook(Book("Book 2", "Author 2", 102));
    library.addBook(Book("Book 3", "Author 3", 103));

    // Display all books in the library
    library.displayAllBooks();

    // Borrowing a book
    library.borrowBook(102);

    // Display all books again after borrowing
    library.displayAllBooks();

    // Returning the book
    library.returnBook(102);

    // Display all books again after returning
    library.displayAllBooks();

    return 0;
}
