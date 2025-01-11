#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int n = S.size();
    int count = 0;
    int i = 0;

    while (i < n) {
        if (i + 1 < n && S[i] == '0' && S[i + 1] == '0') {
            count++;
            i += 2;
        } else {
            count++;
            i++;
        }
    }

    cout << count << endl;

    return 0;
}
