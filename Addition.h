#pragma once
#include "Question.h"
#include <cstdlib>

class Addition : public Question
{
public:
    Addition() {
        number1 = rand() % 20 + 1;  // Random number between 1-20
        number2 = rand() % 20 + 1;  // Random number between 1-20
    }

    void ask() const override {
        std::cout << number1 << " + " << number2 << " =  \n";
    }

    int getCorrectAnswer() const override { // Overriding the virtual function in the base class
        return number1 + number2;
    }
};