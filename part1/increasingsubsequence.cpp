#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> inputValues(n);
    vector<long long> stack;

    for (int i = 0; i < n; i++) {
        cin >> inputValues[i];
    }

    for (int i = 0; i < n; i++) {
        auto itPointerToStart = lower_bound(stack.begin(), stack.end(), inputValues[i]);

        if (itPointerToStart == stack.end()) {
            stack.push_back(inputValues[i]);
        } else {
            *itPointerToStart = inputValues[i];
        }
    }

    cout << stack.size() << endl;

    return 0;
}