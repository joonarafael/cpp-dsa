#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Booking {
    long long arrival;
    long long departure;
    int roomNumber;
};

bool sortByDepartureTime(const Booking &a, const Booking &b) {
    return a.departure < b.departure;
}

int main() {
    int n;
    cin >> n;

    vector<Booking> bookings(n);

    for (int i = 0; i < n; ++i) {
        cin >> bookings[i].arrival >> bookings[i].departure;
        bookings[i].roomNumber = -1;
    }

    sort(bookings.begin(), bookings.end(), sortByDepartureTime);

    cout << endl;

    return 0;
}
