#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> inputValues(n);

    for (int i = 0; i < n; ++i) {
        cin >> inputValues[i];
    }

    std::stack<pair<int, long long>> heap;

    for (int i = 0; i < n; ++i) {
        while (!heap.empty() && inputValues[i] <= heap.top().second) {
            heap.pop();
        }

        if (heap.empty()) {
            cout << "0 ";
        } else {
            cout << (heap.top().first + 1) << " ";
        }

        heap.push({ i, inputValues[i] });
    }

    cout << endl;

    return 0;
}