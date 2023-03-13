#include <iostream>
#include <vector>
#include <random>

using namespace std;

const int BOARD_SIZE = 9;
const int SUB_SIZE = 3;
const int EMPTY_CELL = 0;

// Define the Sudoku board
vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE, EMPTY_CELL));

// Print the Sudoku board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            cout << board[i][j] << " ";
            if ((j + 1) % SUB_SIZE == 0 && j != BOARD_SIZE - 1) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % SUB_SIZE == 0 && i != BOARD_SIZE - 1) {
            cout << "------+-------+------" << endl;
        }
    }
}

// Check if the given number can be placed in the specified cell
bool is_valid(int row, int col, int num) {
    // Check row
    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (board[row][j] == num) {
            return false;
        }
    }
    // Check column
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][col] == num) {
            return false;
        }
    }
    // Check sub-grid
    int sub_row = row / SUB_SIZE * SUB_SIZE;
    int sub_col = col / SUB_SIZE * SUB_SIZE;
    for (int i = sub_row; i < sub_row + SUB_SIZE; ++i) {
        for (int j = sub_col; j < sub_col + SUB_SIZE; ++j) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Generate a random number in the specified range
int rand_int(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

// Fill the Sudoku board with random numbers
void fill_board() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == EMPTY_CELL) {
                int num;
                do {
                    num = rand_int(1, BOARD_SIZE);
                } while (!is_valid(i, j, num));
                board[i][j] = num;
            }
        }
    }
}

int main() {
    fill_board();
    print_board();
    return 0;
}
