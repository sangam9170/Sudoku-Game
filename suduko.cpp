#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <stack>

using namespace std;

class Sudoku {
private:
    vector<vector<int>> board;
    const int SIZE = 9; // Size of the Sudoku board
    const int SUBGRID_SIZE = 3; // Size of the subgrid
    const int EMPTY_CELL = 0; // Representing empty cells
    stack<pair<int, pair<int, int>>> moves; // For undo functionality

public:
    Sudoku() {
        board = vector<vector<int>>(SIZE, vector<int>(SIZE, EMPTY_CELL));
        srand(static_cast<unsigned int>(time(0))); // Seed for random generation
    }

    void setupBoard(int difficulty) {
        fillBoard();
        int cellsToRemove = (difficulty == 1) ? 36 : (difficulty == 2) ? 50 : 64; // Easy, Medium, Hard
        removeNumbers(cellsToRemove);
    }

    bool fillBoard() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    vector<int> numbers = getRandomNumbers();
                    for (int num : numbers) {
                        if (isValidMove(i, j, num)) {
                            board[i][j] = num;
                            if (fillBoard()) return true; // Recursive call
                            board[i][j] = EMPTY_CELL; // Reset on backtrack
                        }
                    }
                    return false; // No valid number found, backtrack
                }
            }
        }
        return true; // All cells filled
    }

    void removeNumbers(int count) {
        int removed = 0;
        while (removed < count) {
            int row = rand() % SIZE;
            int col = rand() % SIZE;
            if (board[row][col] != EMPTY_CELL) {
                board[row][col] = EMPTY_CELL;
                removed++;
            }
        }
    }

    vector<int> getRandomNumbers() {
        vector<int> numbers(SIZE);
        iota(numbers.begin(), numbers.end(), 1); // Fill numbers 1-9
        random_shuffle(numbers.begin(), numbers.end()); // Shuffle numbers
        return numbers;
    }

    void displayBoard() {
        cout << "-------------------------\n";
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (j % SUBGRID_SIZE == 0) cout << "| ";
                cout << (board[i][j] == EMPTY_CELL ? ". " : to_string(board[i][j]) + " ");
            }
            cout << "|\n";
            if ((i + 1) % SUBGRID_SIZE == 0) cout << "-------------------------\n";
        }
    }

    bool isValidMove(int row, int col, int num) {
        // Check row and column
        for (int i = 0; i < SIZE; ++i) {
            if (board[row][i] == num || board[i][col] == num) return false;
        }

        // Check 3x3 box
        int startRow = row - row % SUBGRID_SIZE, startCol = col - col % SUBGRID_SIZE;
        for (int i = 0; i < SUBGRID_SIZE; ++i)
            for (int j = 0; j < SUBGRID_SIZE; ++j)
                if (board[i + startRow][j + startCol] == num) return false;

        return true;
    }

    bool isSolved() {
        for (const auto& row : board) {
            for (int cell : row) {
                if (cell == EMPTY_CELL) return false; // At least one cell is empty
            }
        }
        return true;
    }

    void hint() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (board[i][j] == EMPTY_CELL) {
                    for (int num = 1; num <= SIZE; ++num) {
                        if (isValidMove(i, j, num)) {
                            cout << "Hint: You can place " << num << " at (" << (i + 1) << ", " << (j + 1) << ")\n";
                            return;
                        }
                    }
                }
            }
        }
        cout << "No hints available.\n";
    }

    void undo() {
        if (!moves.empty()) {
            auto lastMove = moves.top();
            moves.pop();
            board[lastMove.second.first][lastMove.second.second] = EMPTY_CELL; // Reset the cell
            cout << "Last move undone.\n";
        } else {
            cout << "No moves to undo.\n";
        }
    }

    void saveGame(const string& filename) {
        ofstream file(filename);
        for (const auto& row : board) {
            for (int cell : row) {
                file << cell << " ";
            }
            file << "\n";
        }
        file.close();
        cout << "Game saved successfully!\n";
    }

    void loadGame(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error loading game file.\n";
            return;
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                file >> board[i][j];
            }
        }
        file.close();
        cout << "Game loaded successfully!\n";
    }

    void playGame() {
        int difficulty;
        cout << "Select difficulty level (1: Easy, 2: Medium, 3: Hard): ";
        cin >> difficulty;

        setupBoard(difficulty);
        int row, col, num;
        while (true) {
            displayBoard();
            cout << "Enter row (1-9), column (1-9), and number (1-9) or 0 to quit: ";
            cin >> row;

            // Check if user wants to quit
            if (row == 0) break; 

            cin >> col >> num;

            // Validate input
            if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9) {
                cout << "Invalid input. Please enter values within the range (1-9).\n";
                continue; // Go back to the beginning of the loop
            }

            row--; // Convert to 0-based index
            col--;

            // Validate move
            if (isValidMove(row, col, num)) {
                moves.push({num, {row, col}}); // Store the move for undo
                board[row][col] = num;
                if (isSolved()) {
                    displayBoard();
                    cout << "Congratulations, you've solved the Sudoku!" << endl;
                    return;
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }

            cout << "Enter 1 for hint, 2 to save, 3 to load, 4 to undo, or 0 to continue: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                hint();
            } else if (choice == 2) {
                saveGame("sudoku_save.txt");
            } else if (choice == 3) {
                loadGame("sudoku_save.txt");
            } else if (choice == 4) {
                undo();
            }
        }
    }
};

int main() {
    Sudoku game;
    game.playGame();
    return 0;
}
