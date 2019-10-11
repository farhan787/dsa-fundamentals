// Find all possible paths

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

char maze[][10] = {
    "0000X",
    "0000X",
    "0000X",
    "0X000",
    "00000",
};

int count = 0;

bool ratInAMaze(char maze[][10], int paths[][10], int m, int n, int i, int j) {
    // Base Case
    if (i == m && j == n) {
        // reached the destination
        paths[i][j] = 1;

        // print the path
        for (int x = 0; x <= m; x++) {
            for (int y = 0; y <= n; y++) {
                cout << paths[x][y] << " ";
            }
            cout << endl;
        }
        cout << endl;
        count++;

        return true;
    }

    // rat should never go out of the maze
    if (i > m || j > n) {
        return false;
    }

    if (maze[i][j] == 'X') {
        return false;
    }

    // Assume solution exists through current cell
    paths[i][j] = 1;

    bool canMoveDown = ratInAMaze(maze, paths, m, n, i + 1, j);
    bool canMoveRight = ratInAMaze(maze, paths, m, n, i, j + 1);

    paths[i][j] = 0;

    if (canMoveRight || canMoveDown) {
        return true;
    }

    return false;
}

int main() {
    int paths[10][10] = {0};

    int m, n;
    m = 5;
    n = 5;

    bool result = ratInAMaze(maze, paths, m, n, 0, 0);
    if (!result) cout << "No solution for this input" << endl;

    if (result) cout << "Total number of paths: " << count << endl;
}

