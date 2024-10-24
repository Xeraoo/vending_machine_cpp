//
// Created by Xeraoo on 23.11.2020.
//

#include "Automat.h"
#include "Platnosc.h"
#include "Karta.h"
#include "Blik.h"
#include "Odczyt.h"

Automat::Automat() {
    // Initialize dynamic arrays for drink quantities and objects
    ilosc = new int[SIZE];
    for(int i = 0; i < SIZE; i++) {
        ilosc[i] = 3; // Default quantity is 3 for each product
    }

    napoj = new Napoj[SIZE]; // Dynamic array of drink objects
    // Initialize drink products
    napoj[0].uzupelnij(0, "Piwniczanka", 2.0);
    napoj[1].uzupelnij(1, "Herbata", 3.7);
    napoj[2].uzupelnij(2, "Coca Cola", 6.1);
    napoj[3].uzupelnij(3, "Schweppes", 10.0);
}

// Display the available drinks in the vending machine
void Automat::wyswietl() {
    std::cout << "|"; 
    for(int i = 0; i < 54; i++) { std::cout << "-"; } 
    std::cout << "|" << std::endl;

    std::cout << "|" << "\t\tVENDING MACHINE\t\t" << "       |" << std::endl;

    std::cout << "|"; 
    for(int i = 0; i < 54; i++) { std::cout << "."; } 
    std::cout << "|" << std::endl;

    std::cout << "|" << " Available drinks:" << "\t\t\t\t       |" << std::endl;

    // Display drink details: ID, name, price, and available quantity
    for(int j = 0; j < SIZE; j++) {
        std::cout << "|" << " ID: " << napoj[j].ID 
                  << " " << napoj[j].nazwa 
                  << " Price: " << napoj[j].cena 
                  << " PLN " << " Available: " << ilosc[j] << " |" << std::endl;
    }

    std::cout << "|"; 
    for(int i = 0; i < 54; i++) { std::cout << "_"; } 
    std::cout << "|" << std::endl;
}

// Let the user choose a drink, check availability
int Automat::wybor() {
    auto* od = new odczyt;
    int wyb;

    do {
        std::cout << "Select a product (enter its number): " << std::endl;
        wyb = od->czytInt(); // Get user input

        // Check product availability based on user input
        if(wyb >= 0 && wyb < SIZE) {
            if(ilosc[wyb] == 0) {
                std::cout << "Product unavailable, please select another.\n";
                wyb = -1; // Invalid selection, repeat loop
            } else {
                std::cout << "Selected product: " << napoj[wyb].nazwa << std::endl;
            }
        } else {
            std::cout << "Invalid selection, try again." << std::endl;
        }
    } while(wyb < 0 || wyb >= SIZE);

    return wyb;
}

// Handle payment process (cash, card, BLIK)
void Automat::nominal() {
    auto* k = new Karta;   // For card payment
    auto* b = new Blik;    // For BLIK payment
    auto* od = new odczyt; // For reading user input
    int metoda, wartosc;
    float cena;

    int wyb = wybor(); // Get product selection
    cena = napoj[wyb].cena; // Set product price

    // Display the price to the user
    std::cout << "Amount to pay: " << cena << " PLN" << std::endl;

    // Choose payment method
    std::cout << "Select payment method:\n1. Cash\n2. Card\n3. BLIK" << std::endl;
    metoda = od->czytInt();

    switch (metoda) {
        case 1: {
            wartosc = static_cast<int>(cena * 100); // Convert to cents
            handleCashPayment(wartosc);
            break;
        }
        case 2: {
            k->zaplac(); // Card payment
            break;
        }
        case 3: {
            b->zaplac(); // BLIK payment
            break;
        }
        default:
            std::cout << "No payment method selected. Transaction canceled." << std::endl;
            return;
    }

    // Reduce the quantity of the selected product
    ilosc[wyb]--;
}

// Handle cash payment process
void Automat::handleCashPayment(int& wartosc) {
    auto* od = new odczyt;
    const int nom[6]{500, 200, 100, 50, 20, 10}; // Accepted coins: 5zł, 2zł, 1zł, 50gr, 20gr, 10gr
    int coin;
    bool inTab = false;

    std::cout << "Accepted coins: 5zł, 2zł, 1zł, 50gr, 20gr, 10gr\nNo change is given." << std::endl;

    do {
        std::cout << "Insert coin: " << std::endl;
        coin = od->czytInt();

        // Check if coin is valid
        for (int i = 0; i < 6; i++) {
            if (nom[i] == coin) {
                inTab = true;
                break;
            }
        }

        if (inTab) {
            wartosc -= coin;
            std::cout << "Remaining amount: " << wartosc / 100.0 << " PLN" << std::endl;
        } else {
            std::cout << "Invalid coin. Try again." << std::endl;
        }

    } while (wartosc > 0 && inTab);
}

// Check if payment is complete
bool Automat::sprawdz(int& wartosc) {
    if (wartosc == 0) {
        std::cout << "Product purchased successfully." << std::endl;
        return true;
    }
    return false;
}

// Check if the machine is out of stock
bool Automat::zawartosc() {
    for (int j = 0; j < SIZE; j++) {
        if (ilosc[j] != 0) return false;
    }
    return true;
}

// Destructor for freeing dynamically allocated memory
Automat::~Automat() {
    delete[] ilosc;
    delete[] napoj;
    std::cout << "Program ended." << std::endl;
}
