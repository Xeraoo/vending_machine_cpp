//
// Created by Xeraoo on 17.12.2020.
//

#ifndef XEROO_ETAP1_BLIK_H   // Zmieniono na XEROO_ETAP1_BLIK_H, aby dostosować do nowej konwencji nazewnictwa
#define XEROO_ETAP1_BLIK_H

#include "Platnosc.h"
#include <chrono>

// The Blik class is a subclass of Platnosc, representing a specific payment method
class Blik : public Platnosc {
public:
    Blik() = default;       // Constructor, default used here
    void zaplac() const override;  // Polymorphic method to handle the BLIK payment
    ~Blik() override = default;    // Destructor, marked as 'default' for better clarity
};

#endif //XEROO_ETAP1_BLIK_H
