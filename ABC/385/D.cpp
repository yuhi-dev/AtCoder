#include <iostream>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &pair) const {
        return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
    }
    unordered_set<pair<long long, long long>, pair_hash> houses;

int main() {
int main() {
    int N, M;
    long long Sx, Sy;
    cin >> N >> M >> Sx >> Sy;

    unordered_set<pair<long long, long long>, hash<pair<long long, long long>>> houses;
    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        houses.insert({x, y});
    }

    unordered_set<pair<long long, long long>, pair_hash> visited;
    for (int i = 0; i < M; ++i) {
        char D;
        long long C;
        cin >> D >> C;
        moves[i] = {D, C};
    }

    unordered_set<pair<long long, long long>, hash<pair<long long, long long>>> visited;
    long long x = Sx, y = Sy;
    for (const auto& move : moves) {
        char D = move.first;
        long long C = move.second;
        if (D == 'U') {
            for (long long i = 1; i <= C; ++i) {
                if (houses.count({x, y + i})) {
                    visited.insert({x, y + i});
                }
            }
            y += C;
        } else if (D == 'D') {
            for (long long i = 1; i <= C; ++i) {
                if (houses.count({x, y - i})) {
                    visited.insert({x, y - i});
                }
            }
            y -= C;
        } else if (D == 'L') {
            for (long long i = 1; i <= C; ++i) {
                if (houses.count({x - i, y})) {
                    visited.insert({x - i, y});
                }
            }
            x -= C;
        } else if (D == 'R') {
            for (long long i = 1; i <= C; ++i) {
                if (houses.count({x + i, y})) {
                    visited.insert({x + i, y});
                }
            }
            x += C;
        }
    }

    cout << x << " " << y << " " << visited.size() << endl;
    return 0;
}