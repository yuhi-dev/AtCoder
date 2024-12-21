#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    int maxBuildings = 1;
    for (int d = 1; d < N; ++d) {
        unordered_map<int, int> count;
        for (int i = 0; i + d < N; ++i) {
            if (H[i] == H[i + d]) {
                count[H[i]]++;
                maxBuildings = max(maxBuildings, count[H[i]]);
                cout << count[H[i]] << endl;
            }
        }
    }

    cout << maxBuildings << endl;
    return 0;
}