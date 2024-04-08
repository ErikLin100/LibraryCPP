#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <iostream>

class Book {
private:
    std::string title; // Kirjan nimi
    std::string author; // Kirjan kirjoittaja
    std::string isbn; // Kirjan ISBN

public:
    // Konstruktori
    Book(const std::string& t, const std::string& a, const std::string& i) 
        : title(t), author(a), isbn(i) {}

    // Getter-metodit
    std::string getTitle() const { return title; } // Palauttaa kirjan nimen
    std::string getAuthor() const { return author; } // Palauttaa kirjan kirjoittajan
    std::string getIsbn() const { return isbn; } // Palauttaa kirjan ISBN-numeron

    // Tulostaa kirjan tiedot
    void display() const {
        std::cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn << std::endl;
    }
};

#endif // BOOK_HPP