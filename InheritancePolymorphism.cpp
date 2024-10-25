#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory> 
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"

using namespace std;

int main()
{

#ifdef _DEBUG
    // _CrtSetBreakAlloc();
    _onexit(_CrtDumpMemoryLeaks);
#endif

    cout << "Welcome to Twenty Questions\n";
    cout << " ===========================\n";
    cout << "Twenty random addition or subtraction questions with operands between 1 and 20. How many can you get right?\n";

    srand((unsigned int)time(nullptr));
    int correctAnswers = 0;
    int totalQuestions = 20;

    vector<unique_ptr<Question>> questions;

    for (int i = 0; i < totalQuestions; i++) {
        int questionType = rand() % 3;

        switch (questionType) {
        case 0:
            questions.push_back(make_unique<Addition>());       // Addition
            break;
        case 1:
            questions.push_back(make_unique<Subtraction>());    // Subtraction
            break;
        case 2:
            questions.push_back(make_unique<Multiplication>());  // Multiplication
            break;
        }
    }

    for (int i = 0; i < totalQuestions; i++) {
        int userAnswer;
        questions[i]->ask();  // Ask the question
        cin >> userAnswer;    // Get user's answer

        // Check if the answer is correct
        if (userAnswer == questions[i]->getCorrectAnswer()) {
            cout << "Correct!\n";
            correctAnswers++;  // Increment correct answers count
        }
        else {
            cout << "Wrong! The correct answer is " << questions[i]->getCorrectAnswer() << ".\n";
        }
    }

    // Display final score
    cout << "You got " << correctAnswers << " out of " << totalQuestions << " questions correct.\n";

}


