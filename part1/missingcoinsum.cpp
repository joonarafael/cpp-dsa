#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int missingCoinSum(vector<long long>& arr, int n) {
    long long int res = 1;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n && arr[i] <= res; i++) {
        res = res + arr[i];
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    std::vector<long long> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << missingCoinSum(arr, n) << endl;

    return 0;
}
