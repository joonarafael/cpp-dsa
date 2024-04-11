#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long elementsInRange(long long value, long long n) {
    long long count = 0;

    for (long long i = 1; i <= n; i++) {
        count += min(n, value / i);
    }
    
    return count;
}

int main() {
    long long n;
    cin >> n;

    long long lowerBound = 0;
    long long upperBound = n * n;

    // binary search
    while(upperBound - lowerBound > 1) {
        long long middle = lowerBound + (upperBound - lowerBound) / 2;

        if (elementsInRange(middle, n) < (n * n + 1) / 2) {
            lowerBound = middle;
        } else {
            upperBound = middle;
        }
    }

    cout << lowerBound + 1 << endl;

    return 0;
}