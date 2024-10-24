//
// Created by Xeraoo on 23.11.2020.
//

#ifndef PROJEKCIK_AUTOMAT_H
#define PROJEKCIK_AUTOMAT_H

#include "Napoj.h"

// Define a constant for the size of the array (number of products)
constexpr int SIZE = 4;  // Global constant used to define the size of arrays

// Automat class manages the vending machine operations
class Automat {
private:
    Napoj* napoj;   // Pointer to store an array of drinks
    int* ilosc;     // Pointer to store an array of quantities for each drink

public:
    Automat();              // Constructor
    void wyswietl();         // Method to display available products
    int wybor();             // Method to allow the user to select a product
    void nominal();          // Method to handle payment processes
    static bool sprawdz(int& i);  // Method to check if the payment is completed
    bool zawartosc();        // Method to check if the vending machine is empty
    ~Automat();              // Destructor

};

#endif // PROJEKCIK_AUTOMAT_H
