#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;
int N;

void dfs(int v, int p) {
    subtree_size[v] = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        dfs(u, v);
        subtree_size[v] += subtree_size[u];
    }
}

int main() {
    cin >> N;
    adj.resize(N + 1);
    subtree_size.resize(N + 1);

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    int min_deletions = N;
    for (int i = 1; i <= N; ++i) {
        int max_subtree = 0;
        for (int u : adj[i]) {
            if (subtree_size[u] < subtree_size[i]) {
                max_subtree = max(max_subtree, subtree_size[u]);
            } else {
                max_subtree = max(max_subtree, N - subtree_size[i]);
            }
        }
        min_deletions = min(min_deletions, max_subtree);
    }

    cout << min_deletions << endl;
    return 0;
}