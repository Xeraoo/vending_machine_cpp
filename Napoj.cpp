//
// Created by Xeraoo on 23.11.2020.
//

#include "Napoj.h"

// Constructor for the Napoj class, initializing the attributes
Napoj::Napoj(int id, std::string n, float p) : ID(id), nazwa(std::move(n)), cena(p) {}

// Method to update the attributes of the Napoj class
void Napoj::update(int id, std::string n, float c) {
    ID = id;
    nazwa = std::move(n);  // Using move to optimize string assignment
    cena = c;
}

// Destructor for the Napoj class (empty in this case)
Napoj::~Napoj() {}
