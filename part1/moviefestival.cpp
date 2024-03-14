#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Movie {
    int start;
    int end;
};

bool sortByEndTime(const Movie &a, const Movie &b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<Movie> movies(n);

    for (int i = 0; i < n; ++i) {
        cin >> movies[i].start >> movies[i].end;
    }

    sort(movies.begin(), movies.end(), sortByEndTime);

    int count = 1;
    int endTime = movies[0].end;

    for (int i = 1; i < n; ++i) {
        if (movies[i].start >= endTime) {
            count++;
            endTime = movies[i].end;
        }
    }

    cout << count << endl;

    return 0;
}
