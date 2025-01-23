#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
int n, m, dist[N][N];

void bfs()
{
    queue<pair<int, int>> q;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dist[i][j] = INT_MAX;
    dist[n][0] = 0;
    q.push({n, 0});

    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        for(int football = 0; football <= m; football++){
            int music = m - football;
            if(football <= u.first && music <= u.second && dist[u.first - football + music][u.second - music + football] > dist[u.first][u.second] + 1){
                dist[u.first - football + music][u.second - music + football] = dist[u.first][u.second] + 1;
                q.push({u.first - football + music, u.second - music + football});
            }
        }
    }

    cout << (dist[0][n] == INT_MAX ? -1 : dist[0][n]) << '\n';
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    freopen("EXTICKET.inp", "r", stdin);
    freopen("EXTICKET.out", "w", stdout);

    while(cin >> n >> m){
        bfs();
    }

    return 0;
}
