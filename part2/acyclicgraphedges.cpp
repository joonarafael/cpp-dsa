#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> result(m);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        if (a > b) {
            result[i] = make_pair(b, a);
        } else {
            result[i] = make_pair(a, b);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}
