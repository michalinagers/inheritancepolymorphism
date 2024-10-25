#pragma once
#include "Question.h"
#include <cstdlib>

class Multiplication : public Question
{

public:

    Multiplication() {
        number1 = rand() % 20 + 1;  //random number between 1-20 and assign it to the variable
        number2 = rand() % 20 + 1;
    }

    void ask() const override {
        std::cout << number1 << " * " << number2 << " =  \n";
    }

    int getCorrectAnswer() const override {
        return number1 * number2;
    }
};