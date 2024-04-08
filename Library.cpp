#include "Library.hpp"
#include <fstream> // Tiedostojen käsittelyyn tarvittava kirjasto

// Tallentaa kirjat tiedostoon
void Library::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    for (const auto& book : books) {
        outFile << book.getTitle() << "\n"
                << book.getAuthor() << "\n"
                << book.getIsbn() << "\n";
    }
    outFile.close();
}

// Lataa kirjat tiedostosta
void Library::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::string title, author, isbn;

    // Tyhjentää nykyiset kirjat
    books.clear();

    while (std::getline(inFile, title) &&
           std::getline(inFile, author) &&
           std::getline(inFile, isbn)) {
        books.emplace_back(title, author, isbn); // Lisää kirjan kirjastoon
    }
    inFile.close();
}