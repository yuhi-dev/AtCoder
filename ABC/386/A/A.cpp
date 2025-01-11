#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool canBeFullHouse(const vector<int>& cards) {
    map<int, int> freq;

    for (int card : cards) {
        freq[card]++;
    }

    if (freq.size() > 2) return false;

    vector<int> counts;
    for (auto& p : freq) {
        counts.push_back(p.second);
    }

    if (counts.size() == 2) {
        return (counts[0] == 3 && counts[1] == 2) || (counts[0] == 2 && counts[1] == 3);
    }

    return false;
}

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    vector<int> cards = {A, B, C, D};

    for (int i = 1; i <= 13; i++) {
        vector<int> newCards = cards;
        newCards.push_back(i);

        if (canBeFullHouse(newCards)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
