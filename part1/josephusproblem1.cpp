#include <iostream>
#include <vector>

using namespace std;

void josephusOrder(int n) {
    vector<bool> isAlive(n + 1, true);

    int aliveCount = n;
    int position = -1;

    while (aliveCount > 1) {
        int interval = 2;

        while (interval > 0) {
            position = (position + 1) % n;

            if (isAlive[position + 1]) {
                interval--;
            }
        }

        isAlive[position + 1] = false;
        aliveCount--;

        cout << position + 1 << " ";
    }

    for (int i = 1; i <= n; ++i) {
        if (isAlive[i]) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    int n;
    cin >> n;

    josephusOrder(n);

    return 0;
}
