#include <math.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool canPlace(int sudoku[][9], int number, int i, int j, int n) {
    // check for the rows
    for (int x = 0; x < n; x++) {
        if (sudoku[x][j] == number) return false;
    }

    // check for the columns
    for (int y = 0; y < n; y++) {
        if (sudoku[i][y] == number) return false;
    }

    // check for the sub-grids
    int rn = sqrt(n);
    int sx = (i / rn) * rn;
    int sy = (j / rn) * rn;

    for (int x = sx; x < sx + rn; x++) {
        for (int y = sy; y < sy + rn; y++) {
            if (sudoku[x][y] == number) return false;
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[][9], int i, int j, int n) {
    // Base case
    if (i == n) {
        // print the sudoku
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                cout << sudoku[x][y] << " ";
            }
            cout << endl;
        }

        return true;
    }

    if (j == n) {
        return sudokuSolver(sudoku, i + 1, 0, n);
    }

    // skip the pre-filled cells
    if (sudoku[i][j] != 0) {
        return sudokuSolver(sudoku, i, j + 1, n);
    }

    for (int number = 1; number <= n; number++) {
        if (canPlace(sudoku, number, i, j, n)) {
            sudoku[i][j] = number;

            bool isSudokuSolving = sudokuSolver(sudoku, i, j + 1, n);
            if (isSudokuSolving) return true;
        }
    }

    sudoku[i][j] = 0;
    return false;
}

int main() {
    int sudoku[][9] = {
        {0, 0, 8, 6, 0, 0, 3, 4, 0},
        {1, 6, 0, 0, 7, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 5, 0},
        {0, 0, 9, 1, 0, 0, 0, 0, 2},
        {6, 0, 0, 0, 0, 0, 0, 3, 8},
        {0, 0, 0, 8, 0, 0, 0, 1, 4},
        {3, 9, 0, 0, 0, 6, 1, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 5},
        {5, 8, 1, 7, 0, 2, 0, 0, 0},
    };

    int n = 9;

    bool canBeSolved = sudokuSolver(sudoku, 0, 0, n);
    if (!canBeSolved) cout << "This sudoku puzzle is invalid and can\'t be solved" << endl;
}

