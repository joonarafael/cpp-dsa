#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if ((n * (n + 1) / 2) % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES\n";

    std::vector< long long > arr1;
    std::vector< long long > arr2;

    if (n % 2 == 0) {
        long long fromStart = 1;
        long long fromEnd = n;

        for (long long i = 0; i < n / 4; ++i) {
            arr1.push_back(fromStart);
            fromStart += 1;
            arr2.push_back(fromStart);
            fromStart += 1;

            arr1.push_back(fromEnd);
            fromEnd -= 1;
            arr2.push_back(fromEnd);
            fromEnd -= 1;
        }
    } else {
        int turns[8] = {0, 0, 1, 0, 1, 1, 0, 1};

        for (long long i = 0; i < n; ++i) {
            int thisTurn = turns[i % 8];

            if (thisTurn == 0) {
                arr1.push_back(i + 1);
            } else {
                arr2.push_back(i + 1);
            }
        }
    }

    cout << arr1.size() << "\n";

    for (std::vector<long long>::size_type i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }

    cout << "\n" << arr2.size() << "\n";

    for (std::vector<long long>::size_type i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }

    cout << endl;

    return 0;
}
