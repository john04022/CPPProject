#include <iostream>
#include <vector>

using namespace std;

class ChainReaction {
private:
    vector<vector<int> > board;
    int rows, cols;

public:
    ChainReaction(int r, int c) : rows(r), cols(c), board(r, vector<int>(c, 0)) {}

    void addBall(int x, int y) {
        if (x < 0 || x >= rows || y < 0 || y >= cols) {
            cout << "Invalid move!" << endl;
            return;
        }
        board[x][y]++;
        if (board[x][y] > 4) {
            explode(x, y);
        }
        printBoard();
    }

    void explode(int x, int y) {
        board[x][y] = 0;
        if (x > 0) board[x-1][y]++;
        if (x < rows-1) board[x+1][y]++;
        if (y > 0) board[x][y-1]++;
        if (y < cols-1) board[x][y+1]++;

        // Recursive explosions
        if (x > 0 && board[x-1][y] > 4) explode(x-1, y);
        if (x < rows-1 && board[x+1][y] > 4) explode(x+1, y);
        if (y > 0 && board[x][y-1] > 4) explode(x, y-1);
        if (y < cols-1 && board[x][y+1] > 4) explode(x, y+1);
    }

    void printBoard() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main() {
    ChainReaction game(5, 5); // 5x5 board
    game.addBall(2, 2);
    game.addBall(2, 2);
    game.addBall(2, 2);
    game.addBall(2, 2);
    game.addBall(2, 2); // This should cause an explosion

    game.addBall(3, 2);
    game.addBall(3, 2);
    game.addBall(3, 2);
    game.addBall(3, 2);
    game.addBall(3, 2); // This should cause an explosion
    return 0;
}
