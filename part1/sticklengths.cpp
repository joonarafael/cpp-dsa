#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    std::vector<long long> sticks(n);

    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    long long totalCost = 0;

    for (int i = 0; i < n; i++) {
        long long distanceFromMedian = abs(sticks[i] - sticks[n / 2]);
        totalCost += distanceFromMedian;
    }

    cout << totalCost << endl;

    return 0;
}
