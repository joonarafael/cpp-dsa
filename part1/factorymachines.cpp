#include <iostream>
#include <vector>

using namespace std;

const long long MAX = 1e18;

int main() {
    int n; // amount of machines
    int m; // amount of products

    cin >> n >> m;

    vector<int> machines(n);

    for (int i = 0; i < n; ++i) {
        cin >> machines[i];
    }

    long long lowerBound = 0;
    long long upperBound = MAX;
    long long result = MAX;

    // binary search
    while (lowerBound <= upperBound) {
        long long middle = (lowerBound + upperBound) / 2;
        long long products = 0;

        for (int i = 0; i < n; ++i) {
            products += min(middle / machines[i], 1000000000LL);
        }

        if (products >= m) {
            result = middle;
            upperBound = middle - 1;
        } else {
            lowerBound = middle + 1;
        }
    }

    cout << result << endl;

    return 0;
}