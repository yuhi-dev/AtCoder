#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }
    string T;
    cin >> T;

    set<pair<int, int>> visitedHouses;
    int x = X - 1, y = Y - 1;

    for (char move : T) {
        if (move == 'U' && x > 0 && grid[x - 1][y] != '#') {
            x--;
        } else if (move == 'D' && x < H - 1 && grid[x + 1][y] != '#') {
            x++;
        } else if (move == 'L' && y > 0 && grid[x][y - 1] != '#') {
            y--;
        } else if (move == 'R' && y < W - 1 && grid[x][y + 1] != '#') {
            y++;
        }
        if (grid[x][y] == '@') {
            visitedHouses.insert({x, y});
        }
    }

    cout << x + 1 << " " << y + 1 << " " << visitedHouses.size() << endl;
    return 0;
}