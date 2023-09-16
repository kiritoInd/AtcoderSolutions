#include <iostream>
#include <vector>
#include <array>
#include <limits.h>

using namespace std;

typedef long long int ll;

void dfs(vector<vector<array<int, 3>>>& G, vector<pair<ll, ll>>& pos, vector<bool>& visited, int v, ll x, ll y) {
    visited[v] = true;
    pos[v] = {x, y};
    for (const array<int, 3>& edge : G[v]) {
        int vv = edge[0];
        ll dx = edge[1];
        ll dy = edge[2];
        if (!visited[vv]) {
            dfs(G, pos, visited, vv, x + dx, y + dy);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 3>>> G(n);
    for (int i = 0; i < m; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--, b--;
        G[a].push_back({b, x, y});
        G[b].push_back({a, -x, -y});
    }

    vector<pair<ll, ll>> pos(n);
    vector<bool> visited(n, false);

    dfs(G, pos, visited, 0, 0, 0);

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            cout << pos[i].first << ' ' << pos[i].second << endl;
        } else {
            cout << "undecidable" << endl;
        }
    }

    return 0;
}
