#include <iostream>
#include <string>

using namespace std;

void displayBoard(char board[8][8])
{
    cout << "\n  a b c d e f g h\n";

    for (int i = 0; i < 8; i++)
    {
        cout << 8 - i << " ";

        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }

        cout << 8 - i << endl;
    }

    cout << "  a b c d e f g h\n";
}

int main()
{
    char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    bool whiteTurn = true;
    string from, to;

    while (true)
    {
        displayBoard(board);

        if (whiteTurn)
            cout << "\nWhite's turn\n";
        else
            cout << "\nBlack's turn\n";

        cout << "Enter move (example: e2 e4) or 'quit': ";
        cin >> from;

        // Exit the game
        if (from == "quit")
        {
            cout << "Game ended.\n";
            break;
        }

        cin >> to;

        // Convert chess coordinates to array indexes
        int fromCol = from[0] - 'a';
        int fromRow = 8 - (from[1] - '0');

        int toCol = to[0] - 'a';
        int toRow = 8 - (to[1] - '0');

        // Check if coordinates are valid
        if (fromCol < 0 || fromCol > 7 ||
            toCol < 0 || toCol > 7 ||
            fromRow < 0 || fromRow > 7 ||
            toRow < 0 || toRow > 7)
        {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        // Check if the starting square is empty
        if (board[fromRow][fromCol] == '.')
        {
            cout << "There is no piece at that position!\n";
            continue;
        }

        // Check White's turn
        if (whiteTurn &&
            !(board[fromRow][fromCol] >= 'A' &&
              board[fromRow][fromCol] <= 'Z'))
        {
            cout << "That is not a White piece!\n";
            continue;
        }

        // Check Black's turn
        if (!whiteTurn &&
            !(board[fromRow][fromCol] >= 'a' &&
              board[fromRow][fromCol] <= 'z'))
        {
            cout << "That is not a Black piece!\n";
            continue;
        }

        // Move the piece
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = '.';

        // Change turn
        whiteTurn = !whiteTurn;
    }

    return 0;
}