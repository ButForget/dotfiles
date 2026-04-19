#include <bits/stdc++.h>

using namespace std;

struct State {
    long long cost;
    int penalty;
    int node;

    bool operator>(const State &other) const {
        return cost > other.cost;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }

    vector<vector<uint16_t>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(static_cast<uint16_t>(v));
        graph[v].push_back(static_cast<uint16_t>(u));
    }

    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    const int INF = numeric_limits<int>::max();
    vector<int> min_penalty(n + 1, INF);
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, 1});

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        if (cur.node == n) {
            cout << cur.cost << '\n';
            return 0;
        }

        // PDF-style pruning: only expand states that improve the minimum
        // accumulated penalty seen for this node.
        if (cur.penalty >= min_penalty[cur.node]) {
            continue;
        }
        min_penalty[cur.node] = cur.penalty;

        for (uint16_t next_raw : graph[cur.node]) {
            int next = static_cast<int>(next_raw);
            int next_penalty = cur.penalty + b[next];
            if (next_penalty >= min_penalty[next]) {
                continue;
            }

            long long next_cost = cur.cost + cur.penalty + a[next];
            pq.push({next_cost, next_penalty, next});
        }
    }

    cout << -1 << '\n';
    return 0;
}
