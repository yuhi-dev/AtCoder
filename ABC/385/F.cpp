#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Building {
    long long x, h;
};

bool canSeeAllBuildings(double height, const vector<Building>& buildings) {
    double maxSlope = -1e18;
    for (const auto& building : buildings) {
        double slope = (building.h - height) / building.x;
        if (slope <= maxSlope) {
            return false;
        }
        maxSlope = slope;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<Building> buildings(N);
    for (int i = 0; i < N; ++i) {
        cin >> buildings[i].x >> buildings[i].h;
    }

    double low = 0, high = 1e9;
    for (int i = 0; i < 100; ++i) { // Binary search with 100 iterations for precision
        double mid = (low + high) / 2;
        if (canSeeAllBuildings(mid, buildings)) {
            low = mid;
        } else {
            high = mid;
        }
    }

    if (canSeeAllBuildings(0, buildings)) {
        cout << -1 << endl;
    } else {
        cout << fixed << setprecision(18) << low << endl;
    }

    return 0;
}