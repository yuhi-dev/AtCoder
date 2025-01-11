#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int total_sum = 0;
    int excluded_sum = 0;

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            int value = i * j;
            total_sum += value;
            if (value == X) {
                excluded_sum += value;
            }
        }
    }

    cout << total_sum - excluded_sum << endl;

    return 0;
}
