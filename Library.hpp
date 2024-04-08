#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Book.hpp"
#include <vector>
#include <iostream>
#include <fstream> // Tiedostojen käsittelyyn tarvittava kirjasto
#include <string>
#include <algorithm>  // Algoritmien käyttö, kuten std::find_if

class Library {
private:
    std::vector<Book> books; // Kirjojen säilyttämiseen käytettävä vektori

public:
    // Lisää kirjan kirjastoon
    void addBook(const Book& book) {
        // Tarkistaa, onko kirja jo kirjastossa
        auto it = std::find_if(books.begin(), books.end(), [&book](const Book& b) {
            return b.getIsbn() == book.getIsbn(); // Vertailee kirjojen ISBN-tunnuksia
        });

        if (it != books.end()) {
            std::cout << "A book with the ISBN " << book.getIsbn() << " already exists.\n";
            return; // Palauttaa, jos kirja on jo kirjastossa
        }

        books.push_back(book); // Lisää kirjan, jos ISBN on uniikki
        std::cout << "Book added successfully.\n";
    }

    // Listaa kirjat
    void listBooks() const {
        if (books.empty()) {
            std::cout << "The library is currently empty.\n";
            return;
        }
        for (size_t i = 0; i < books.size(); ++i) {
            std::cout << i + 1 << ". ";
            books[i].display(); // Näyttää kirjan tiedot
        }
    }

    // Tallentaa kirjat tiedostoon
    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        for (const auto& book : books) {
            outFile << book.getTitle() << "\n"
                    << book.getAuthor() << "\n"
                    << book.getIsbn() << "\n";
        }
        outFile.close();
    }

    // Lataa kirjat tiedostosta
    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        std::string title, author, isbn;

        books.clear(); // Tyhjentää nykyiset kirjat

        while (std::getline(inFile, title) &&
               std::getline(inFile, author) &&
               std::getline(inFile, isbn)) {
            books.emplace_back(title, author, isbn); // Lisää kirjan kirjastoon
        }
        inFile.close();
    }

    // Poistaa kirjan indeksin perusteella
    void removeBookByIndex(int index) {
        if (index >= 0 && index < books.size()) {
            books.erase(books.begin() + index);
            std::cout << "Book removed successfully.\n";
        }
        else {
            std::cout << "Invalid index. No book removed.\n";
        }
    }

    // Palauttaa kirjojen lukumäärän
    int getBookCount() const {
        return books.size();
    }
};

#endif // LIBRARY_HPP