#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
const int N = 9;
int m, n;
int board[4][4]; // the board
int dirLine[] = {1, 0, -1,
                 0}; // mapping it with the values (i.e.) the change in the
                     // line/column at the value '0' (s--down) &&
int dirColumn[] = {0, 1, 0,
                   -1}; // '1' (d--right) && '2' (w--up) && '3' (a--left)

class Game
{
public:
    pair<int, int> generateUnoccupiedPosition() // to generate unoccupied cells
    {
        int occupied = 1, line, column;

        while (occupied)
        {
            line = rand() % 4;
            column = rand() % 4;

            if (board[line][column] == 0)
                occupied = 0;
            else
                continue;
        }

        return make_pair(line, column);
    }

    void addPiece() //  to add the value to the board
    {
        pair<int, int> pos = generateUnoccupiedPosition();
        board[pos.first][pos.second] = 2;
    }

    void newGame() // after the user selects New Game option
    {
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                board[i][j] = 0;

        addPiece();
    }

    bool canDoMove(int line, int column, int nextLine, int nextColumn)
    {
        if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 ||
            (board[line][column] != board[nextLine][nextColumn] &&
             board[nextLine][nextColumn] != 0))
            return false;
        return true;
    }

    void printGUI() // to give values of the cells after the valid move
    {
        system("cls");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (board[i][j] == 0)
                    cout << setw(4) << "*";
                else
                    cout << setw(4) << board[i][j];
            }
            cout << endl;
        }

        cout << "n:New Game || s:Down || d:Right || w:Up || a:Left || q:Quit \n";
    }

    void applyMove(int direction)
    {
        int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;

        if (direction == 0)
        {
            startLine = 3;
            lineStep = -1;
        }

        if (direction == 1)
        {
            startColumn = 3;
            columnStep = -1;
        }

        int movePossible = 0, canAddPiece = 0;

        do
        {

            movePossible = 0;
            for (int i = startLine; i >= 0 && i < 4; i += lineStep)
                for (int j = startColumn; j >= 0 && j < 4; j += columnStep)
                {
                    int nextI = i + dirLine[direction], nextJ = j + dirColumn[direction];
                    if (canDoMove(i, j, nextI, nextJ) && board[i][j])
                    {
                        board[nextI][nextJ] += board[i][j];
                        board[i][j] = 0;
                        movePossible = canAddPiece = 1;
                    }
                }
            printGUI(); // to show the changing values
        } while (movePossible);

        if (canAddPiece)
        {
            addPiece();
        }
    }
    int game1()
    {
        char commandToDir[128];
        //   Controllers
        //   s--> to move the cells downward
        //   d--> to ove the cells right
        //   w--> to move the cells upward
        //   a--> to ove the cells left
        commandToDir['s'] = 0;
        commandToDir['d'] = 1;
        commandToDir['w'] = 2;
        commandToDir['a'] = 3;
        newGame();

        while (true)
        {
            printGUI();
            char command;
            cin >> command;
            if (command == 'q' || command == 'n' || command == 'w' || command == 'a' || command == 's' || command == 'd')
            {
                if (command == 'q')
                    break;
                else if (command == 'n')
                    newGame();
                else
                {
                    int currentDirection = commandToDir[command];
                    applyMove(currentDirection);
                }
            }
            else
            {
                cout << "Invalid Choice...Enter Again." << endl;
                system("pause");
            }
        }
        return 0;
    }


class Screen : public Game
{
public:
    void Rules()
    {
        // cout << "__________________________________________*" << endl;
        system("cls");
        cout << "\n\t\t\t__________________________________________________________"
                "__________________________________\n";
        cout << "\n\t\t\t|\t\t\t\t\tRULES / INSTRUCTIONS\t\t\t\t   |";
        cout << "\n\t\t\t__________________________________________________________"
                "__________________________________\n";

        cout << "\n\t\t\t\t\t\t\t       # HOW TO PLAY 2048 GAME " << endl;
        cout << "\t\t\t____________________________________________________________"
                "________________________________";
        cout
            << "\n\nThe basic rules of the game 2048 is very simple.The objective "
               "of the game is to fill a 9x9 grid with digits so that each column, "
               "each row, and each of the nine 3x3 sub-grids that compose the grid "
               "contain all of the digits from 1 to 9.The game starts with a "
               "partially filled grid. Your task is to fill in the missing numbers "
               "(represented by 0) to solve the puzzle.You can enter a number from "
               "1 to 9 in an empty cell. The cell can be selected by specifying "
               "the row and column number.You cannot enter the same number in the "
               "same row, column, or 3x3 sub-grid.If you enter an invalid number, "
               "you will be prompted to enter a different number.If you are unable "
               "to solve the puzzle, you can view the solution by entering -1 as "
               "the row, column, and number.The game will end when you have "
               "successfully filled in all the missing numbers, or when you choose "
               "to view the solution.If you successfully solve the puzzle, you "
               "will be congratulated. Otherwise, you will be encouraged to try "
               "again. Enjoy the game and have fun!"
            << endl;
        cout << "\t\t\t____________________________________________________________"
                "________________________________\n";
        cout << "\n\t\t\t\t\t\t\t       # HOW TO PLAY SUDOKU GAME " << endl;
        cout << "\t\t\t____________________________________________________________"
                "________________________________";
        cout << "\n\nThe objective of the game is to fill a 9x9 grid with digits "
                "so that each column, each row, and each of the nine 3x3 sub-grids "
                "that compose the grid contain all of the digits from 1 to 9.The "
                "game starts with a partially filled grid. Your task is to fill in "
                "the missing numbers (represented by 0) to solve the puzzle.You "
                "can enter a number from 1 to 9 in an empty cell. The cell can be "
                "selected by specifying the row and column number.You cannot enter "
                "the same number in the same row, column, or 3x3 sub-grid.If you "
                "enter an invalid number, you will be prompted to enter a "
                "different number.If you are unable to solve the puzzle, you can "
                "view the solution by entering -1 as the row, column, and "
                "number.The game will end when you have successfully filled in all "
                "the missing numbers, or when you choose to view the solution.If "
                "you successfully solve the puzzle, you will be congratulated. "
                "Otherwise, you will be encouraged to try again.Enjoy the game and "
                "have fun!"
             << endl;
        cout << "\t\t\t____________________________________________________________"
                "________________________________\n";
        cout << "\n\t\t\t\t\t\t\t       # HOW TO PLAY WORD SEARCH GAME " << endl;
        cout << "\t\t\t____________________________________________________________"
                "________________________________";
        cout << "\n\nThe game is played on a rectangular board made up of cells. "
                "The board size is specified by the user as number of rows and "
                "columns.The user inputs characters for each cell in the board.The "
                "user will be presented with two options-a Search a new word b "
                "Quit If the user selects.Search a new word, they will be prompted "
                "to enter a word to search for in the board.The user will not be "
                "allowed to search for a word with only one character.The program "
                "will search the board for the given word and display the result:a "
                "If the word is found, the program will display the starting "
                "position of the word.b If the word is not found, the program will "
                "display a message indicating that the word was not found.The game "
                "will continue until the user selects Quit.!"
             << endl;
        cout << "\t\t\t____________________________________________________________"
                "________________________________\n";

        cout << "\n\t\t\t|\t\t\t\tPRESS 1 FOR GOING BACK\n";
        cout << "\n\t\t\t|\t\t\t\t";
        int a;
        cin >> a;
        if (a == 1)
            WelcomeScreen();
    }
    bool solveSudoku(int board2[9][9], int row, int col)
    {
        // If all cells are filled, the puzzle is solved
        if (row == 9 - 1 && col == 9)
            return true;

        // Move to the next row if the current column is N
        if (col == 9)
        {
            row++;
            col = 0;
        }

        // Skip the cells that already have a value
        if (board2[row][col] != 0)
            return solveSudoku(board2, row, col + 1);

        // Try filling the current cell with a number from 1 to 9
        for (int num = 1; num <= 9; num++)
        {
            if (isSafe(board2, row, col, num))
            {
                board2[row][col] = num;

                if (solveSudoku(board2, row, col + 1))
                    return true;

                board2[row][col] = 0;
            }
        }
        return false;
    }
    void playGame(int board2[9][9])
    {
        int ch;
        int row, col, num;
        while (true)
        {
            printBoard(board2);
            cout << endl
                 << endl;
            cout << "Unable to solve? Enter -1 as row, col and num to view the "
                    "solved sudoku."
                 << endl;
            cout << "Enter row: ";
            cin >> row;
            cout << "Enter column: ";
            cin >> col;
            cout << "Enter number: ";
            cin >> num;

            if (row == -1 || col == -1 || num == -1)
            {
                solveSudoku(board2, 0, 0);
                printBoard(board2);
                cout << endl;
                cout << "Better luck next time!!!" << endl;
                system("pause");
                WelcomeScreen();
            }
            if (isSolvedCompletely(board2))
                break;
            row--;
            col--;
            if (!isSafe(board2, row, col, num))
            {
                cout << "Invalid move. Try again." << endl;
                continue;
            }
            board2[row][col] = num;
        }

        // Check if the user has solved it correctly or not
        bool solved = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board2[i][j] == 0)
                {
                    solved = false;
                    break;
                }
            }
        }

        if (solved)
        {
            cout << "Congratulations! You have solved the puzzle." << endl;
            printBoard(board2);
        }
        else
        {
            cout << "Puzzle not solved. Better luck next time." << endl;
        }
    }
    void printBoard(int grid[9][9])
    {

        system("cls");
        cout << "\t\t\t<==========================================================="
                "=====================>"
             << endl;
        cout << "\t\t\t|                             WELCOME TO SUDOKU!            "
                "                     |"
             << endl;
        cout << "\t\t\t|       Fill in the missing numbers(represented by 0) to "
                "solve the puzzle.       |"
             << endl;
        cout << "\t\t\t<==========================================================="
                "=====================>"
             << endl;
        for (int row = 0; row < 9; row++)
        {
            for (int col = 0; col < 9; col++)
            {
                if (col == 3 || col == 6)
                    cout << " | ";
                cout << grid[row][col] << " ";
            }
            if (row == 2 || row == 5)
            {
                cout << endl;
                for (int i = 0; i < 9; i++)
                    cout << "---";
            }
            cout << endl;
        }
    }
    bool isSafe(int board[N][N], int row, int col, int num)
    {
        // Check if 'num' is already in the same row
        for (int i = 0; i < N; i++)
            if (board[row][i] == num)
                return false;

        // Check if 'num' is already in the same column
        for (int i = 0; i < N; i++)
            if (board[i][col] == num)
                return false;

        // Check if 'num' is already in the same 3x3 box
        int boxRowStart = row - row % 3;
        int boxColStart = col - col % 3;

        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i + boxRowStart][j + boxColStart] == num)
                    return false;

        return true;
    }
    bool isSolvedCompletely(int grid[N][N])
    {
        for (int row = 0; row < N; row++)
            for (int col = 0; col < N; col++)
                if (grid[row][col] == 0)
                    return false;

        return true;
    }

    void sudoku()
    {
        system("cls");
        cout << "\t\t\t<==========================================================="
                "=====================>"
             << endl;
        cout << "\t\t\t|                             WELCOME TO SUDOKU!            "
                "                     |"
             << endl;
        cout << "\t\t\t|       Fill in the missing numbers(represented by 0) to "
                "solve the puzzle.       |"
             << endl;
        cout << "\t\t\t<==========================================================="
                "=====================>"
             << endl;
        int board2[9][9] = {
            {2, 9, 0, 0, 0, 0, 7, 0, 6}, {0, 6, 3, 0, 2, 9, 0, 0, 0}, {0, 0, 0, 6, 5, 0, 0, 0, 2}, {1, 0, 8, 2, 0, 6, 0, 0, 4}, {0, 2, 7, 0, 8, 0, 5, 0, 0}, {0, 3, 0, 0, 0, 0, 0, 0, 8}, {5, 8, 4, 9, 7, 2, 0, 0, 0}, {0, 0, 0, 0, 0, 5, 8, 4, 0}, {0, 0, 0, 0, 0, 8, 0, 0, 0}};
        int choice;
        cout << endl
             << endl;
        cout << "\t\t[1] Solve the Sudoku" << endl;
        cout << "\t\t[2] Unable to solve? View the solved Sudoku" << endl;
        cout << "\t\t[3] Exit" << endl;
        cout << "\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playGame(board2);
            break;
        case 2:
            if (solveSudoku(board2, 0, 0))
            {
                system("cls");
                cout << "Completely Solved Sudoku is: " << endl;
                cout << endl
                     << endl;
                for (int row = 0; row < 9; row++)
                {
                    for (int col = 0; col < 9; col++)
                    {
                        if (col == 3 || col == 6)
                            cout << " | ";
                        cout << board2[row][col] << " ";
                    }
                    if (row == 2 || row == 5)
                    {
                        cout << endl;
                        for (int i = 0; i < N; i++)
                            cout << "---";
                    }
                    cout << endl;
                }
                cout << endl;
                cout << "Better luck next time!!!" << endl;
                system("pause");
                WelcomeScreen();
            }
            else
                cout << "No solution found" << endl;
            break;
        case 3:
            WelcomeScreen();
        default:
            cout << "Invalid Choice...Enter Again." << endl;
            system("pause");
            sudoku();
        }
    }

    bool searchWord(vector<vector<char>> &board, string word, int row, int col,
                    int index)
    {
        // Base case
        if (index == word.size())
        {
            return true;
        }

        // Check boundaries of board
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
        {
            return false;
        }

        // Check if the character in the board matches with the character in the
        // word
        if (board[row][col] != word[index])
        {
            return false;
        }

        // Mark the current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Check in all the directions for the next character in the word
        bool found = searchWord(board, word, row + 1, col, index + 1) ||
                     searchWord(board, word, row - 1, col, index + 1) ||
                     searchWord(board, word, row, col + 1, index + 1) ||
                     searchWord(board, word, row, col - 1, index + 1);

        // Mark the current cell as unvisited
        board[row][col] = temp;

        return found;
    }

    void findWords(vector<vector<char>> &board, string word)
    {
        // Iterate through all cells of the board
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                // Check if the current cell matches with the first character of the
                // word
                if (board[i][j] == word[0])
                {
                    // If yes, check in all the directions for the remaining characters of
                    // the word
                    if (searchWord(board, word, i, j, 0))
                    {
                        cout << "Found word " << word << " starting at (" << i << ", " << j
                             << ")" << endl;
                        return;
                    }
                }
            }
        }

        cout << "Word " << word << " not found in the board!" << endl;
    }

    void takeInput(vector<vector<char>> board)
    {
        string word;
        cout << "Enter the word to search: ";
        cin >> word;
        while (word.size() == 1)
        {
            cout << "Invalid input" << endl;
            cout << "Enter the word to search: ";
            cin >> word;
        }
        findWords(board, word);
    }

    void selectOption(vector<vector<char>> board)
    {
        int option = 1;
        do
        {
            cout << endl
                 << "Select an option" << endl;
            cout << "1. Search a new word" << endl;
            cout << "2. Quit" << endl;
            cin >> option;
            switch (option)
            {
            case 1:
                takeInput(board);
                break;
            case 2:
                cout << "Thanks for playing!" << endl;
                system("pause");
                WelcomeScreen();
                break;
            default:
                cout << "Invalid Choice...Enter Again." << endl;
            }
        } while (option != 2);
    }
    void wordsearch()
    {
        system("cls");
        int rows = 0, cols = 0;
        cout << "\t\t\t\t\t\t\t\t---------WORD SEARCH GAME---------" << endl;
        do
        {
            cout << "\nEnter the number of rows and columns of the board: ";
            cin >> rows >> cols;

        } while (rows == 0 || cols == 0);

        vector<vector<char>> board(rows, vector<char>(cols));
        cout << "Enter the board characters row-wise: " << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> board[i][j];
            }
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << board[i][j] << "|";
            }
            cout << endl;
        }
        selectOption(board);
    }
    void WelcomeScreen()
    {
        system("cls");
        int choice;
        cout << "\t\t\t\t\t                  _________________________" << endl;
        cout << "\t\t\t\t\t                 < Welcome to ARCADIUM !!! >" << endl;
        cout << "\t\t\t\t\t                  -------------------------" << endl;
        cout << "\t\t\t\t\t                         \\   ^__^" << endl;
        cout << "\t\t\t\t\t                          \\  (oo)\\_______" << endl;
        cout << "\t\t\t\t\t                             (__)\\       )\\/\\ " << endl;
        cout << "\t\t\t\t\t                                 ||----w |" << endl;
        cout << "\t\t\t\t\t                                 ||     ||" << endl;
        cout << "\t\t\t------------------------------------------------------------"
                "------------------------------"
             << endl;
        cout << "\t\t\t------------------------------------------------------------"
                "------------------------------"
             << endl;
        cout << "\t\t\t************************************************************"
                "******************************"
             << endl;
        cout << "\t\t\t*\t\t\t\t\t1-Play 2048 Game\t\t\t\t" << endl
             << "\t\t\t\t\t\t\t\t2-Play Sudoku Game" << endl
             << "\t\t\t\t\t\t\t\t"
             << "3-Word Search Game" << endl
             << "\t\t\t\t\t\t\t\t4-Rules and Instructions" << endl
             << "\t\t\t\t\t\t\t\t5-Quit Game\t\t\t\t\t*" << endl;
        cout << "\t\t\t************************************************************"
                "******************************"
             << endl;
        cout << "\t\t\t------------------------------------------------------------"
                "------------------------------"
             << endl;
        cout << "\t\t\t------------------------------------------------------------"
                "------------------------------"
             << endl;
        cout << "\t\t\t**\t\t\t\t\tEnter your choice" << endl;
        cout << "\t\t\t  \t\t\t\t\t";
        cin >> choice;
        if (choice == 1)

        {
            game1();
            WelcomeScreen();
        }
        else if (choice == 2)
        {
            sudoku();
        }
        else if (choice == 3)
        {
            wordsearch();
            WelcomeScreen();
        }
        else if (choice == 4)
        {

            Rules();
        }
        else if (choice == 5)
        {

            exit(0);
        }
        else
        {
            cout << "Invalid Choice...Enter Again." << endl;
            WelcomeScreen();
        }
    }
};

int main()
{
    Screen s;
    s.WelcomeScreen();
}
