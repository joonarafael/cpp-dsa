#include <iostream>
#include <vector>

using namespace std;

int mod = 1e9+7;

int main() {
    int n;
    cin >> n;

    int totalSum = n * (n + 1) / 2;

    if (totalSum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    int subsetSum = totalSum / 2;

    std::vector<vector<int>> sumMemory(n, std::vector<int>(subsetSum + 1, 0));

    sumMemory[0][0] = 1;

    for (int lowerBound = 1; lowerBound < n; lowerBound++) {
        for (int upperBound = 0; upperBound <= subsetSum; upperBound++) {
            sumMemory[lowerBound][upperBound] = sumMemory[lowerBound - 1][upperBound];

            int difference = upperBound - lowerBound;

            if (difference >= 0) {
                int valueToAdd = sumMemory[lowerBound - 1][difference];
                sumMemory[lowerBound][upperBound] += valueToAdd;

                int result = sumMemory[lowerBound][upperBound] % mod;
                sumMemory[lowerBound][upperBound] = result;
            }
        }
    }

    int result = sumMemory[n - 1][subsetSum];

    cout << result << endl;

    return 0;
}
