#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(time(0));

    int numberToGuess = rand() % 100 + 1;
    int playerGuess = 0;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100." << endl;

    while (playerGuess != numberToGuess)
    {
        cout << "Enter your guess: ";
        cin >> playerGuess;
        attempts++;

        if (playerGuess > numberToGuess)
        {
            cout << "Too high! Try again." << endl;
        }
        else if (playerGuess < numberToGuess)
        {
            cout << "Too low! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the correct number." << endl;
            cout << "It took you " << attempts << " attempts." << endl;
        }
    }

    return 0;
}
