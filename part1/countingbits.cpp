#include <iostream>
#include <map>

using namespace std;

long long recursive(long long x, map<long long, long long>& memory) {
    if (x == 0) {
        return 0;
    }

    if (memory.find(x) != memory.end()) {
        return memory[x];
    }

    if (x & 1) {
        return memory[x] = 2 * recursive(x / 2, memory) + (x / 2) + 1;
    } else {
        return memory[x] = recursive(x / 2, memory) + recursive(x / 2 - 1, memory) + (x / 2);
    }
}

int main() {
    long long n;
    cin >> n;

    map<long long, long long> memory;

    cout << recursive(n, memory) << endl;

    return 0;
}
