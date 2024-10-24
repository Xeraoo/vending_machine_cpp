//
// Created by Xeraoo on 21.12.2020.
//

#ifndef PROJECT_FILE_H
#define PROJECT_FILE_H

#include <iostream>
#include <string>
#include <fstream>

// Class responsible for reading data from either a file or user input
class Reader {
public:
    // Default constructor
    Reader() = default;

    // Methods for reading integer and string data
    int readInt(); // Determines whether to read from file or prompt for user input
    std::string readString();

    // Default destructor
    ~Reader() = default;
};

#endif //PROJECT_FILE_H
