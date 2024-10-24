#include "Karta.h"
#include "Odczyt.h"

void Karta::zaplac() const {
    std::string PIN;
    odczyt od; // Zamiast dynamicznego przydzielania pamięci, używamy obiektu lokalnego
    bool zgodnosc;

    std::cout << "..........................................\n"
                 "\t  Karta Platnicza\n"
                 ".........................................."
              << std::endl;

    std::cout << "Podaj nastepujace informacje:" << std::endl;

    do {
        std::cout << "Numer PIN (jest to ciag 4 cyfr):" << std::endl;
        PIN = od.czytString(); // Bez dynamicznego alokowania pamięci, po prostu odwołanie do funkcji

        // Sprawdzanie poprawności PINu
        zgodnosc = (PIN.size() == 4 && std::all_of(PIN.begin(), PIN.end(), ::isdigit)); // Sprawdzenie czy wszystkie znaki są cyframi

        if (!zgodnosc) {
            std::cout << "Blad, PIN powinien skladac sie z dokladnie 4 cyfr" << std::endl;
        }
    } while (!zgodnosc);

    std::cout << "..........................................\n"
                 "\t Zakupiono produkt\n"
                 ".........................................."
              << std::endl;
}
