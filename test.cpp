#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 16;  // Spielfeldgröße
const int MINES = 99; // Anzahl der Minen

void placeMines(vector<vector<int> >& field) { // Leerzeichen zwischen >
    srand(time(0));
    int placedMines = 0;
    while (placedMines < MINES) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (field[row][col] == -1) continue; // Mine schon da
        field[row][col] = -1; // Mine platzieren
        placedMines++;
    }
}


void calculateNumbers(vector<vector<int> >& field) { // Leerzeichen zwischen >
    const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (field[row][col] == -1) continue; // Feld ist eine Mine
            int mineCount = 0;
            for (int i = 0; i < 8; i++) {
                int newRow = row + dx[i];
                int newCol = col + dy[i];
                if (newRow >= 0 && newRow < SIZE && newCol >= 0 && newCol < SIZE && field[newRow][newCol] == -1) {
                    mineCount++;
                }
            }
            field[row][col] = mineCount; // Anzahl der Minen setzen
        }
    }
}

void printField(const vector<vector<int> >& field) { // Leerzeichen zwischen >
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (field[row][col] == -1) {
                cout << "* ";
            } else {
                cout << field[row][col] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > field(SIZE, vector<int>(SIZE, 0)); // Leerzeichen zwischen >

    // Minen platzieren und Zahlen berechnen
    placeMines(field);
    calculateNumbers(field);

    // Ergebnis ausgeben
    printField(field);

    return 0;
}
