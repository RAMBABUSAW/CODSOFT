#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// A 3x3 array representing the game board.

char current_Player = 'X';
 // A character representing the current player ('X' or 'O').


void displayBoard()
// Prints the current state of the game board.
{
    cout << "Current Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkDraw() 
// Checks if all positions on the board are filled without a winner, indicating a draw.
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer() 
// Switches the current player between 'X' and 'O'.
{
    current_Player = (current_Player == 'X') ? 'O' : 'X';
}

void makeMove() 
// Prompts the current player to enter a move and updates the board accordingly. It ensures the move is valid and the selected cell is not already occupied.

{
    int move;
    cout << "Player " << current_Player << ", enter your move (1-9): ";
    cin >> move;

    while (move < 1 || move > 9 || board[(move-1)/3][(move-1)%3] == 'X' || board[(move-1)/3][(move-1)%3] == 'O') {
        cout << "Invalid move. Try again: ";
        cin >> move;
    }

    board[(move-1)/3][(move-1)%3] = current_Player;
}

void resetBoard() 
// Resets the board to the initial state with numbers 1-9.
{
    int num = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '0' + num;
            num++;
        }
    }
}

int main() 
// Controls the game loop, alternating turns, checking for win/draw conditions, and prompting players if they want to play again.
{
    bool playAgain = true;
    while (playAgain) {
        resetBoard();
        current_Player = 'X';
        bool gameOver = false;
        
        while (!gameOver) {
            displayBoard();
            makeMove();
            if (checkWin()) {
                displayBoard();
                cout << "Player " << current_Player << " wins!" << endl;
                gameOver = true;
            } else if (checkDraw()) {
                displayBoard();
                cout << "The game is a draw!" << endl;
                gameOver = true;
            } else {
                switchPlayer();
            }
        }

        char response;
        cout << "Do you want to play again? (y/n): ";
        cin >> response;
        if (response != 'y' && response != 'Y') {
            playAgain = false;
        }
    }

    cout << "Thanks for playing!" << endl;
    return 0;
}