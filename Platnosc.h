//
// Created by Xeraoo on 17.12.2020.
//

#ifndef PROJECT_PAYMENT_H
#define PROJECT_PAYMENT_H

#include <iostream>
#include "Automat.h"

// Base class for payment methods
class Payment {
public:
    // Default constructor
    Payment() {};

    // Virtual method for payment processing
    virtual void pay() const {};

    // Virtual destructor
    virtual ~Payment() {};
};

#endif //PROJECT_PAYMENT_H
