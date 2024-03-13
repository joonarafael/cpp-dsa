#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;

    cin >> n;

    std::vector <long long> raw(n + 1); // raw input
    std::vector <long long> aug(n + 1); // augmented ordering

    for(int i = 1; i <= n; ++i){
        cin >> raw[i];
        aug[raw[i]] = i;
    }

    long long moves = 1;

    for(long long i = 2; i <= n; ++i){
        if(aug[i] < aug[i - 1]) {
            moves++;
        }
    }

    cout << moves << endl;

    return 0;
}