#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;
long long everySolution[1000010][2];

int main() {
    int t;
    cin >> t;

    everySolution[1][0] = 1;
    everySolution[1][1] = 1;

    for (int i = 0; i < 1000000; ++i) {
        everySolution[i][0] %= mod;
        everySolution[i][1] %= mod;
		everySolution[i + 1][0] += 2 * everySolution[i][0];
        everySolution[i + 1][0] += everySolution[i][1];
		everySolution[i + 1][1] += everySolution[i][0];
		everySolution[i + 1][1] += 4 * everySolution[i][1];
    }

    for (int i = 0; i < t; ++i) {
        int height;
        cin >> height;

        cout << (everySolution[height][0] + everySolution[height][1]) % mod << endl;
    }

    return 0;
}