#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long arr[n];

    for (long long i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long moves = 0;

    for (long long i = 0; i < n - 1; ++i) {
        if (arr[i + 1] < arr[i]) {
            moves += arr[i] - arr[i + 1];
            arr[i + 1] = arr[i];
        }
    }

    cout << moves;
    cout << endl;

    return 0;
}
