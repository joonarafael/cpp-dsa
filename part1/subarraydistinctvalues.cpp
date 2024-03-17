#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n; // number of elements
    long long m; // distinct count
    
    cin >> n >> m;

    long long values[n];
    std::map<long long, long long> counts;

    for (long long i = 0; i < n; i++) {
        cin >> values[i];
    }

    long long res = 0;
    long long distinct_count = 0;

    // sliding window

    long long pointer_left = 0;
    long long pointer_right = 0;

    while(pointer_left < n) {
        while(pointer_right < n) {
            bool distinct_count_exceeded;

            if (counts[values[pointer_right]] == 0) {
                distinct_count_exceeded = distinct_count + 1 > m;
            } else {
                distinct_count_exceeded = distinct_count > m;
            }

            if (distinct_count_exceeded) {
                break;
            }

            counts[values[pointer_right]]++; 

            if (counts[values[pointer_right]] == 1) {
                distinct_count++;
            }

            pointer_right++; 
        }

        res += (pointer_right - pointer_left);

        if (counts[values[pointer_left]] == 1) {
            distinct_count--;
        }

        counts[values[pointer_left]]--;
        pointer_left++;
    }

    cout << res << endl;

    return 0;
}