#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long targetSum;
    cin >> n >> targetSum;

    vector<long long> inputValues(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputValues[i];
    }

    vector<vector<long long>> record(n + 1, vector<long long>(targetSum + 1, 0));
    record[0][0] = 1;

    for (int ivIndex = 1; ivIndex <= n; ivIndex++) {
        for (long long currentSum = 0; currentSum <= targetSum; currentSum++) {
            if (inputValues[ivIndex - 1] > currentSum) {
                record[ivIndex][currentSum] = record[ivIndex - 1][currentSum];
            } else {
                record[ivIndex][currentSum] = record[ivIndex - 1][currentSum] + record[ivIndex - 1][currentSum - inputValues[ivIndex - 1]];
            }
        }
    }
 
    cout << record[n][targetSum] << endl;

    return 0;
}
