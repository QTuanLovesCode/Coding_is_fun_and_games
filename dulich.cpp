#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n;
vector<pair<int, long long>> adj[N];
bool visited[N];

struct graphs {
    int u, v;
    long long cost;
};

void dfs(int u, long long cost, long long &sum) {
    visited[u] = true;
    sum += cost;
    for(auto [v, w] : adj[u]) {
        if(!visited[v])
            dfs(v, w, sum);
    }
}

int32_t main(void) 
{
    cin.tie(0)->sync_with_stdio(false);

    freopen("dulich.inp", "r", stdin);
    freopen("dulich.out", "w", stdout);

    cin >> n;

    // vector<graphs> paths;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            long long x;
            cin >> x;
            if(i != j)
                adj[i].push_back({j, x});
            // paths.push_back({i, j, x});
        }
    
    /// MST algorithm
    // sort(begin(paths), end(paths), [&] (const graphs &a, const graphs &b) {
    //     return a.cost < b.cost;
    // });

    /// Greedy + DFS
    for(int i = 1; i <= n; i++)
        sort(begin(adj[i]), end(adj[i]), [&] (const pair<int, long long> &a, const pair<int, long long> &b) {
            return a.second < b.second;
        });

    // for(int i = 1; i <= n; i++)
    //     for(auto [v, w] : adj[i])
    //         cout << i << ' ' << v << ' ' << w << '\n';

    long long ans = LLONG_MAX;
    for(int start = 1; start <= n; start++) {
        long long distance = 0;
        dfs(start, 0ll, distance);
        memset(visited, false, sizeof(visited));
        ans = min(ans, distance);
    }

    cout << ans;
    return 0;
}