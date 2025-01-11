#include <iostream>
#include <string>
using namespace std;

string can_transform_within_k(int k, const string& s, const string& t) {
    int len_s = s.size(), len_t = t.size();

    // 前後の共通部分を削除
    int prefix = 0;
    while (prefix < len_s && prefix < len_t && s[prefix] == t[prefix]) {
        ++prefix;
    }
    int suffix = 0;
    while (suffix < len_s - prefix && suffix < len_t - prefix &&
           s[len_s - 1 - suffix] == t[len_t - 1 - suffix]) {
        ++suffix;
    }

    // 新しい長さ
    int new_len_s = len_s - prefix - suffix;
    int new_len_t = len_t - prefix - suffix;

    // 必要な操作回数
    int replacements = min(new_len_s, new_len_t); // 置換操作
    int additions_deletions = abs(new_len_s - new_len_t); // 挿入・削除操作
    int total_operations = replacements + additions_deletions;

    return total_operations <= k ? "Yes" : "No";
}

int main() {
    int k;
    string s, t;
    cin >> k >> s >> t;
    cout << can_transform_within_k(k, s, t) << endl;
    return 0;
}
