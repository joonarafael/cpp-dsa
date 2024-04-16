#include <queue>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> pq;
    long long result = 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        
        pq.push(t);
        result += pq.top() - t;

        pq.pop();
        pq.push(t);
    }

    cout << result << endl;

    return 0;
}