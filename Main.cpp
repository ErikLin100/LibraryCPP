#include "Library.hpp"
#include <iostream>
#include <string>
#include <limits>

void showMenu() {
    std::cout << "\nLibrary Management System\n"; // Näyttää käyttöliittymän valikon
    std::cout << "1. Add Book\n"; // Lisää kirjan
    std::cout << "2. List Books\n"; // Listaa kirjat
    std::cout << "3. Delete Book\n"; // Poista kirja
    std::cout << "4. Exit\n"; // Poistu
    std::cout << "Enter your choice: "; // Syötä valintasi:
}

int main() {
    Library library;
    library.loadFromFile("library.txt"); // Lataa kirjat tiedostosta 'library.txt'

    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        // Tyhjennä syötepuskuri
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::string title, author, isbn;

        switch (choice) {
            case 1:
                std::cout << "Enter title: "; // Anna kirjan nimi:
                std::getline(std::cin, title);
                std::cout << "Enter author: "; // Anna kirjailija:
                std::getline(std::cin, author);
                std::cout << "Enter ISBN: "; // Anna ISBN:
                std::getline(std::cin, isbn);
                // Nyt addBook() ei tulosta automaattisesti onnistumisviestiä
                library.addBook(Book(title, author, isbn)); // addBook tulostaa itse, onko lisäys onnistunut vai ei
                break;
            case 2:
                library.listBooks(); // Listaa kirjat
                break;
            case 3:
                if(library.getBookCount() == 0) {
                    std::cout << "The library is empty. No books to delete.\n"; // Kirjasto on tyhjä. Ei kirjoja poistettavaksi.
                    break;
                }
                library.listBooks(); // Listaa kirjat
                std::cout << "Enter the number of the book to delete: "; // Syötä poistettavan kirjan numero:
                int index;
                std::cin >> index;
                if (!std::cin.fail() && index > 0 && index <= library.getBookCount()) {
                    library.removeBookByIndex(index - 1); // Poista kirja
                } else {
                    std::cin.clear(); // Tyhjennä virhetunnukset
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ohita huono syöte
                    std::cout << "Invalid input. No book removed.\n"; // Virheellinen syöte. Ei kirjaa poistettu.
                }
                break;
            case 4:
                library.saveToFile("library.txt"); // Tallenna ennen poistumista
                std::cout << "Library saved. Exiting program.\n"; // Kirjasto tallennettu. Poistutaan ohjelmasta.
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n"; // Virheellinen valinta. Yritä uudelleen.
        }
    }
}