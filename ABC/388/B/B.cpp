#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> T(N), L(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> L[i];
    }

    for (int k = 1; k <= D; ++k) {
        int max_weight = 0;
        for (int i = 0; i < N; ++i) {
            int new_length = L[i] + k;
            int weight = T[i] * new_length;
            max_weight = max(max_weight, weight);
        }
        cout << max_weight << endl;
    }

    return 0;
}
