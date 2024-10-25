#pragma once
#include "Question.h"
#include <iostream>
#include <cstdlib>  
class Subtraction : public Question
{

public:

    Subtraction() {
        number1 = rand() % 20 + 1;  //random number between 1-20 and assign it to the variable
        number2 = rand() % 20 + 1;
    }

    void ask() const override {
        std::cout << number1 << " - " << number2 << " =  \n";
    }

    int getCorrectAnswer() const override {
        return number1 - number2;
    }
};
