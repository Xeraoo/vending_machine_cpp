//
// Created by Xeraoo on 23.11.2020.
//

#ifndef PROJECT_NAPOJ_H
#define PROJECT_NAPOJ_H

#include <iostream>
#include <string>

class Napoj {
    friend class Automat; // Friendship declaration: class Automat has access to Napoj's private members
private:
    // Class attributes
    int ID;
    std::string name;
    float price;
public:
    // Explicit constructor with default values
    explicit Napoj(int id = -1, std::string n = "...", float p = 0.0);

    // Method to update the attributes of the class
    void update(int id, std::string n, float p);

    // Destructor
    ~Napoj();
};

#endif //PROJECT_NAPOJ_H
