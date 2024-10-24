//
// Created by Xeraoo on 23.11.2020.
//

#include <iostream>
#include <string>
#include <fstream>
#include "Napoj.h"
#include "Automat.h"
#include "Odczyt.h"

using namespace std;
std::ifstream file;     // Global input file stream

int main(int argc, char **argv) {

    auto *od = new Odczyt;  // Pointer to Odczyt class: methods for reading data from a file or manually input
    if (argc >= 1) {
        file.open(argv[1]);  // Checking if a file is detected
        if (file.good()) {
            cout << "File successfully read" << endl;
            for (int i = 0; i < argc; i++) {
                cout << i << ": " << argv[i] << endl;  // Display the command-line arguments
            }
        } else {
            cout << "File with data not detected" << endl;
        }
    }

    std::cout << "___________________________________________" << std::endl;
    bool exitProgram = false;  // Controls whether to exit or continue the loop
    string decision;  // Stores user's decision about purchasing or exiting
    Automat vendingMachine;  // Create an instance of the vending machine (Automat class)

    do {
        vendingMachine.wyswietl();  // Display products in the machine
        vendingMachine.nominal();   // Handle the payment
        vendingMachine.wyswietl();  // Display updated product status

        if (!vendingMachine.zawartosc()) {  // Check if the vending machine still has products
            cout << "Do you want to purchase another product?\nEnter 'yes' or 'no':" << endl;
            decision = od->czytString();  // Get user decision using the Odczyt class

            if (decision == "yes") {
                exitProgram = false;  // Continue purchasing
            } else if (decision == "no") {
                exitProgram = true;  // Exit the loop
            } else {
                cout << "Error: Unrecognized input." << endl;
                exitProgram = true;
            }
        } else {
            exitProgram = true;
        }
    } while (!exitProgram);  // Loop until the user decides to exit

    if (argc > 1) {
        file.close();  // Close the input file stream if opened
    }
    return 0;
}

// Odczyt class methods: responsible for reading data from a file (if detected) or manual input

// Read integer value either from a file (if exists) or from user input
int Odczyt::czytInt() {
    std::string inputString;

    if (file.good()) {  // If a file was detected, read from it
        std::getline(file, inputString);
        // Remove spaces from the string
        while (inputString.find(' ') != std::string::npos) {
            inputString.erase(inputString.find(' '), 1);
        }
    } else {
        std::getline(std::cin, inputString);  // Otherwise, read input from the user
        while (inputString.find(' ') != std::string::npos) {
            inputString.erase(inputString.find(' '), 1);
        }
    }
    return atoi(inputString.c_str());  // Convert the string to an integer and return it
}

// Read string value either from a file (if exists) or from user input
std::string Odczyt::czytString() {
    std::string inputString;

    if (file.good()) {  // If a file was detected, read from it
        std::getline(file, inputString);
        // Remove spaces from the string
        while (inputString.find(' ') != std::string::npos) {
            inputString.erase(inputString.find(' '), 1);
        }
    } else {
        std::getline(std::cin, inputString);  // Otherwise, read input from the user
        while (inputString.find(' ') != std::string::npos) {
            inputString.erase(inputString.find(' '), 1);
        }
    }
    return inputString;  // Return the processed string
}
