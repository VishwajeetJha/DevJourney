#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    bool available;

    Book(const string& isbn, const string& title, const string& author)
        : isbn(isbn), title(title), author(author), available(true) {}

    string toString() const {
        return isbn + " | " + title + " by " + author + " | " + (available ? "Available" : "Issued");
    }
};

struct Member {
    int memberId;
    string name;
    vector<string> borrowedIsbns;

    Member(int memberId, const string& name)
        : memberId(memberId), name(name) {}

    string toString() const {
        string borrowed = "";
        for (size_t i = 0; i < borrowedIsbns.size(); i++) {
            if (i > 0) borrowed += ", ";
            borrowed += borrowedIsbns[i];
        }
        return "#" + to_string(memberId) + " " + name + " | borrowed: [" + borrowed + "]";
    }
};

class LibraryService {
private:
    map<string, Book> booksByIsbn;
    map<int, Member> membersById;

public:
    void registerBook(const Book& book) {
        booksByIsbn.insert({book.isbn, book});
    }

    void registerMember(const Member& member) {
        membersById.insert({member.memberId, member});
    }

    bool issueBook(int memberId, const string& isbn) {
        if (membersById.find(memberId) == membersById.end() ||
            booksByIsbn.find(isbn) == booksByIsbn.end() ||
            !booksByIsbn.at(isbn).available) {
            return false;
        }

        booksByIsbn.at(isbn).available = false;
        membersById.at(memberId).borrowedIsbns.push_back(isbn);
        return true;
    }

    bool returnBook(int memberId, const string& isbn) {
        if (membersById.find(memberId) == membersById.end() ||
            booksByIsbn.find(isbn) == booksByIsbn.end()) {
            return false;
        }

        auto& borrowed = membersById.at(memberId).borrowedIsbns;
        auto it = find(borrowed.begin(), borrowed.end(), isbn);
        if (it == borrowed.end()) {
            return false;
        }

        borrowed.erase(it);
        booksByIsbn.at(isbn).available = true;
        return true;
    }

    vector<Book> searchByKeyword(const string& keyword) const {
        string key = keyword;
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        vector<Book> result;

        for (const auto& pair : booksByIsbn) {
            string title = pair.second.title;
            string author = pair.second.author;
            transform(title.begin(), title.end(), title.begin(), ::tolower);
            transform(author.begin(), author.end(), author.begin(), ::tolower);

            if (title.find(key) != string::npos || author.find(key) != string::npos) {
                result.push_back(pair.second);
            }
        }
        return result;
    }

    void printState() const {
        cout << "Books:" << endl;
        for (const auto& pair : booksByIsbn) {
            cout << "  " << pair.second.toString() << endl;
        }

        cout << "Members:" << endl;
        for (const auto& pair : membersById) {
            cout << "  " << pair.second.toString() << endl;
        }
    }
};

int main() {
    LibraryService library;

    library.registerBook(Book("978-0134685991", "Effective Java", "Joshua Bloch"));
    library.registerBook(Book("978-1617294945", "Spring in Action", "Craig Walls"));
    library.registerBook(Book("978-1492056270", "Designing Data-Intensive Applications", "Martin Kleppmann"));

    library.registerMember(Member(1, "Aarav"));
    library.registerMember(Member(2, "Meera"));

    cout << "=== Library Catalog Manager ===" << endl;
    cout << "Issue Effective Java to member #1: " << (library.issueBook(1, "978-0134685991") ? "true" : "false") << endl;
    cout << "Issue Effective Java to member #2 (should fail): " << (library.issueBook(2, "978-0134685991") ? "true" : "false") << endl;
    cout << "Return Effective Java from member #1: " << (library.returnBook(1, "978-0134685991") ? "true" : "false") << endl;
    cout << "Issue Effective Java to member #2 (should pass): " << (library.issueBook(2, "978-0134685991") ? "true" : "false") << endl;

    cout << "\nSearch keyword 'data':" << endl;
    vector<Book> matches = library.searchByKeyword("data");
    if (matches.empty()) {
        cout << "  No books found." << endl;
    } else {
        for (const auto& book : matches) {
            cout << "  " << book.toString() << endl;
        }
    }

    cout << endl;
    library.printState();

    return 0;
}
