#include <iostream>
using namespace std;

const int MAX = 1000010;

long long lcd(long long occurrences[]) {
    for (int i = MAX - 1; i >= 1; i--) {
        long long multiples = 0;

        for (int j = i; j <= MAX - 1; j += i) {
            multiples += occurrences[j];
        }

        if (multiples >= 2) {
            cout << i;
            return 0;
        }
    }

    return 0;
}

int main() {
    long long n;
    cin >> n;

    long long arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    long long occurrences[MAX] = {};

    for (int i = 0; i < n; i++) {
        occurrences[arr[i]]++;
    }

    lcd(occurrences);

    cout << endl;
    
    return 0;
}

