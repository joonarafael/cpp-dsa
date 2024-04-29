#include <bits/stdc++.h>
using namespace std;
 
long long noAdjacentDigits(long long num, vector<long long> &memory) {
    // base cases
    if (num == 0) {
        return 1;
    }

    if (num < 0) {
        return 0;
    }

    string numAsString = to_string(num);
    long long res = 0;

    for (int i = 0; i < static_cast<int>(numAsString.size()); i++) {
        res += memory[i];
    }
 
    int previous = 0;

    for (int i = 0; i < static_cast<int>(numAsString.size()); i++) {
        int digit = numAsString[i] - '0';
        int difference = numAsString.size() - 1 - i;

        int below = digit;

        if (previous < digit) {
            below -= 1;
        }

        if (digit != 0) {
            res += below * memory[difference];
        }

        if (digit == previous) {
            return res;
        }

        previous = digit;
    }

    return res + 1;
}
 
int main() {
    long long a;
    long long b;

    cin >> a >> b;
 
    vector<long long> memory(19);

    memory[0] = 1;
    long long res = 1;

    // precalculate the number of ways to form a number with n digits
    for (int i = 1; i < 19; i++) {
        res = res * 9;
        memory[i] = res;
    }
 
    cout << (noAdjacentDigits(b, memory) - noAdjacentDigits(a - 1, memory));
    cout << endl;
 
    return 0;
}