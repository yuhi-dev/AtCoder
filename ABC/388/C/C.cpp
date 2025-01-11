#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long count = 0;

    for (int i = 0; i < N; ++i) {
        auto it = lower_bound(A.begin() + i + 1, A.end(), A[i] * 2);
        count += A.end() - it;
    }

    cout << count << endl;
    return 0;
}
