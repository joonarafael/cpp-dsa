#include <iostream>
#include <vector>
using namespace std;

int MAXIMUM = 1100000;

int main() {
    int n;

    cin >> n;

    vector<int> inputs(n);

    for (int i = 0; i < n; i++) {
        cin >> inputs[i];
    }

    vector<long long> divisors(MAXIMUM, 0);

    for (int i = 1; i < MAXIMUM; i++) {
        for(int j = i; j < MAXIMUM; j += i) {
            divisors[j]++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << divisors[inputs[i]] << endl;
    }

    return 0;
}
