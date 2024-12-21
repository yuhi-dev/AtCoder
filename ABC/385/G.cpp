#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> dp(N + 1, vector<int>(2 * N + 1, 0));
    dp[0][N] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int j = -N; j <= N; ++j) {
            if (j - 1 >= -N) {
                dp[i][j + N] = (dp[i][j + N] + dp[i - 1][j - 1 + N]) % MOD;
            }
            if (j + 1 <= N) {
                dp[i][j + N] = (dp[i][j + N] + dp[i - 1][j + 1 + N]) % MOD;
            }
        }
    }

    cout << dp[N][K + N] << endl;
    return 0;
}