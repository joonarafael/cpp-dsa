#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> gameBoard(n);
    long long boardSum = 0;

    vector<vector<long long>> memory(n, vector<long long>(n));

    for (int i = 0; i < n; ++i) {
        cin >> gameBoard[i];
        boardSum += gameBoard[i];
    }

    for (int pointer_left = n - 1; pointer_left >= 0; pointer_left--) {
        for (int pointer_right = pointer_left; pointer_right < n; pointer_right++) {
            if (pointer_left == pointer_right) {
                memory[pointer_left][pointer_right] = gameBoard[pointer_left];
            } else {
                long long choice_of_choosing_first = gameBoard[pointer_left] - memory[pointer_left + 1][pointer_right];
                long long choice_of_choosing_last = gameBoard[pointer_right] - memory[pointer_left][pointer_right - 1];

                memory[pointer_left][pointer_right] = max(choice_of_choosing_first, choice_of_choosing_last);
            }
        }
    }

    cout << (boardSum + memory[0][n - 1]) / 2;
    cout << endl;

    return 0;
}