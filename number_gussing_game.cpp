#include <iostream>
// For input and output operations.
#include <cstdlib>
// For random number generation functions.
#include <ctime>
// For seeding the random number generator.


using namespace std;

int main() {
    // Seed the random number generator
    srand(time(0));
    
    // Generate a random number between 1 and 100
    int random_Number = rand() % 10 + 1;
    int user_Guess = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 1 and 10:" << endl;
    cout << "Can you guess what it is?" << endl;

    // Loop until the user guesses the correct number
    while (user_Guess != random_Number) {
        cout << "Enter your guess: ";
        cin >> user_Guess;

        if (user_Guess < random_Number) {
            cout << "Too low! Try again." << endl;
        } else if (user_Guess > random_Number) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number:" << endl;
        }
    }

    return 0;
}










