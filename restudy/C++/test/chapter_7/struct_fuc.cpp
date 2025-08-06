#include<bits/stdc++.h>

#define de(x) cerr<<#x << " " <<x <<" "

using namespace std;
// 2025.08.06——17:42:27
struct travel_time {
    int hour;
    int mins;
};
const int Mins_per_hr = 60; // 分钟数

travel_time sum(travel_time t1, travel_time t2);
void showtime(travel t1);
int main() {
    using namespace std;
    travel_time day1 = {5, 45};    // 5 hrs, 45 min
    travel_time day2 = {4, 55};    // 4 hrs, 55 min

    travel_time trip = sum(day1, day2);
    cout << "Two-day total: ";
    show_time(trip);

    travel_time day3= {4, 32};
    cout << "Three-day total: ";
    show_time(sum(trip, day3));
    // cin.get();

    return 0;
}

travel_time sum(travel_time t1, travel_time t2) {
    travel_time total;
    total.mins = (t1.mins + t2.mins) % Mins_per_hr;
    total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;
    return total;
}

void showtime(travel_time t1) {
    cout << t.hours << " hours, " << t.mins << " minutes\n";
}
