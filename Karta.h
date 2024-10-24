//
// Created by Xeraoo on 17.12.2020.
//

#ifndef ETAP1_KARTA_H
#define ETAP1_KARTA_H
#include <iostream>
#include <string>
#include "Platnosc.h"

class Karta : public Platnosc {
public:
    Karta() {};
    void zaplac() const;
    ~Karta() {};
};
#endif // ETAP1_KARTA_H
