#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(time(0));
    int inputValue = 0;
    int lowerLimit = 1;
    int upperLimit = 100;
    int numGuesses = 5;
    int numTurns = 0;
    int chosenNumber = (rand() % 100) + 1;


    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    while (numGuesses >= 0)
    {

        cout << "Range: [" << lowerLimit << "," << upperLimit << "] "
             << "Number of guesses left: " << numGuesses << endl;
        cout << "Your guess: ";
        cin >> inputValue;

        numGuesses--;
        numTurns++;

        if (numGuesses == 0)
        {
            cout << "Out of guesses! My number is " << chosenNumber << endl;
            break;
        }

        if (chosenNumber == inputValue)
        {
            cout << "Congrats! You guessed my number in " << numTurns << " guesses." << endl;
            break;
        }
        else
        {
            if (inputValue < chosenNumber)
            {
                cout << "Wrong! My number is bigger." << endl;
                cout << endl;
                if (inputValue < lowerLimit)
                {
                    continue;
                }
                else
                {
                    lowerLimit = inputValue + 1;
                }
            }
            else
            {
                cout << "Wrong! My number is smaller." << endl;
                cout << endl;
                if (inputValue > upperLimit)
                {
                    continue;
                }
                else
                {
                    upperLimit = inputValue - 1;
                }
            }
        }
    }
    return 0;
}