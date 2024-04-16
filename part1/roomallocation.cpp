#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Booking {
    long long arrival;
    long long departure;
    int index;
};

bool sortByArrivalTime(const Booking &a, const Booking &b) {
    return a.arrival < b.arrival;
}

int main() {
    int n;
    cin >> n;

    vector<Booking> bookings(n);

    for (int i = 0; i < n; ++i) {
        cin >> bookings[i].arrival >> bookings[i].departure;
        bookings[i].index = i;
    }

    sort(bookings.begin(), bookings.end(), sortByArrivalTime);

    vector<int> roomAllocations(n);
    set<pair<int, int>> emptyRooms;

        int roomNumber = 0;

    for (int i = 0; i < n; ++i) {
        if (emptyRooms.empty()) {
            roomNumber += 1;

            roomAllocations[bookings[i].index] = roomNumber;
            emptyRooms.insert({bookings[i].departure, roomNumber});
        } else {
            auto it = emptyRooms.begin();
            pair<int, int> room = *it;

            if (room.first < bookings[i].arrival) {
                roomAllocations[bookings[i].index] = room.second;

                emptyRooms.erase(*emptyRooms.begin());
                emptyRooms.insert({bookings[i].departure, room.second});
            } else {
                roomNumber += 1;

                roomAllocations[bookings[i].index] = roomNumber;
                emptyRooms.insert({bookings[i].departure, roomNumber});
            }
        }
    }

    cout << roomNumber << endl;

    for (int i = 0; i < n; ++i) {
        cout << roomAllocations[i] << " ";
    }

    cout << endl;

    return 0;
}
