#pragma once
#include <iostream>
class Question
{
public:

	Question() : number1(0), number2(0) {}

	virtual ~Question() {}
	virtual void ask() const = 0;
	virtual int getCorrectAnswer() const = 0;

protected:

	int number1;
	int number2;
};

