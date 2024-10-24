//
// Created by Xeraoo on 17.12.2020.
//

#include "Blik.h"
#include "Odczyt.h"

// Implements the payment process using the BLIK method
void Blik::zaplac() const {
    std::string PIN = "0";           // Stores the BLIK code (6-digit number)
    auto* od = new odczyt;           // Pointer to an 'odczyt' object for reading input
    bool zgodnosc = true, czas = true;  // Flags for code validation and time control

    // Display BLIK payment instructions
    std::cout << "..........................................\n\t\tBlik\n.........................................." << std::endl;
    std::cout << "Podaj nastepujace informacje:" << std::endl;

    // Loop to repeatedly prompt for correct BLIK code and check time constraint
    do {
        auto start = std::chrono::steady_clock::now();  // Start timing the user's input

        std::cout << "Kod Blik (jest to ciag 6 cyfr):" << std::endl;
        PIN = od->czytString();  // Read BLIK code using the odczyt class method

        // Check if the input is exactly 6 digits long
        if (PIN.size() == 6) {
            for (char i : PIN) {
                if (!isdigit(i)) {  // Validate that all characters are digits
                    zgodnosc = false;
                    std::cout << "Blad, PIN nie sklada sie z samych cyfr" << std::endl;
                } else zgodnosc = true;
            }
        } else zgodnosc = false;

        // Measure the duration of the input process
        auto koniec = std::chrono::steady_clock::now();
        auto okres = std::chrono::duration_cast<std::chrono::seconds>(koniec - start);

        // Check if the input took more than 120 seconds (2 minutes)
        if (okres.count() > 120) {
            std::cout << "Czas na wprowadzenie kodu minal. Ponowienie proby.\n";
            czas = false;
        } else czas = true;

        // Display the time it took to input the code
        std::cout << "_______\nczas wykonania operacji: " << okres.count() << " sek\n_______" << std::endl;

    } while (zgodnosc == false || czas == false);  // Repeat if the code was invalid or time ran out

    // Confirm the product purchase
    std::cout << "..........................................\n\t zakupiono produkt\n.........................................." << std::endl;
}
