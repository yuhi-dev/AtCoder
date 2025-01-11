#include <iostream>
#include <string>
#include <cstring>
using namespace std;

long long dp[20][2][2][10];

long long digitDP(const string &num, int pos, bool tight, bool has_lead, int max_digit) {
    if (pos == num.size()) {
        return has_lead ? 1 : 0;
    }
    if (dp[pos][tight][has_lead][max_digit] != -1) {
        return dp[pos][tight][has_lead][max_digit];
    }

    long long res = 0;
    int limit = tight ? (num[pos] - '0') : 9;

    for (int digit = 0; digit <= limit; ++digit) {
        bool new_tight = tight && (digit == limit);

        if (!has_lead) { 
            res += digitDP(num, pos + 1, new_tight, digit > 0, digit);
        } else if (digit < max_digit) {
            res += digitDP(num, pos + 1, new_tight, has_lead, max_digit);
        }
    }

    return dp[pos][tight][has_lead][max_digit] = res;
}

long long countSnakeNumbersInRange(long long L, long long R) {
    string R_str = to_string(R);
    memset(dp, -1, sizeof(dp));
    long long countR = digitDP(R_str, 0, true, false, 0);

    string L_str = to_string(L - 1);
    memset(dp, -1, sizeof(dp));
    long long countL = digitDP(L_str, 0, true, false, 0);

    return countR - countL;
}

int main() {
    long long L, R;
    cin >> L >> R;

    cout << countSnakeNumbersInRange(L, R) << endl;
    return 0;
}
