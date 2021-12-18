// SudokuFitness Implimentation. Finds the fittness number of a puzzle.

#include "SudokuFitness.h"

int SudokuFitness::howFit(shared_ptr<Puzzle> puzzle)
{    
    int total = 0;

    auto update_tot = [&total](int cnt[]) {
        for (int i = 0; i < 10; ++i) {
            if (cnt[i] > 1) total = total + (cnt[i] - 1); // found x same in a row/column. x is not a collison with itself, so # of colisions = x-1
        }
    };

    // check row
    for (int i = 0; i < 9; ++i) {
        int count[10] = { 0 };
        for (int j = 0; j < 9; ++j) {
            ++count[puzzle->getArr(i, j)]; // i, then through j
        }
        update_tot(count);
    }

    // check column
    for (int i = 0; i < 9; ++i) {
        int count[10] = { 0 };
        for (int j = 0; j < 9; ++j) {
            ++count[puzzle->getArr(j, i)];
        }
        update_tot(count);
    }

     // check block
    for (int k = 0; k < 9; ++k) {
        int x = (k / 3) * 3;
        int y = (k % 3) * 3;
        int count[10] = { 0 };
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                ++count[puzzle->getArr(i, j)];
            }
        }
        update_tot(count);
    }

	return total;
}