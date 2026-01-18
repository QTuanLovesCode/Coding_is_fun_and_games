#include <bits/stdc++.h>
using namespace std;

int n, m;

int32_t main(void) 
{
    cin.tie(0)->sync_with_stdio(false);

    freopen("cambay.inp", "r", stdin);
    freopen("cambay.out", "w", stdout);

    cin >> n >> m;
    // vector<vector<long long>> a(n + 1, vector<long long>(m + 1));
    vector<bool> rows(n + 1, false), columns(m + 1, false);
    vector<long long> a(n * m + 1);
    vector<pair<int, int>> index(n * m + 1);

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            index[++cnt] = {i, j};

    
    long long Max = 0, Min = 2e9;
    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= m; j++)
    //         cin >> a[i][j],
    //         Max = max(Max, a[i][j]),
    //         Min = min(Min, a[i][j]);

    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= m; j++)
    //         if(a[i][j] == Max || a[i][j] == Min) 
    //             rows[i] = columns[j] = true;

    // int ans = 0;
    // for(int i = 1; i <= n; i++)
    //     for(int j = 1; j <= m; j++)
    //         if(!rows[i] && !columns[j])
    //             ans++;

    // cout << ans;
    for(int i = 1; i <= n * m; i++) 
        cin >> a[i],
        Max = max(Max, a[i]),
        Min = min(Min, a[i]);
    
    for(int i = 1; i <= n * m; i++) {
        pair<int, int> place = index[i];
        if(a[i] == Max || a[i] == Min)
            rows[place.first] = columns[place.second] = true;
    }

    int ans = 0;
    for(int i = 1; i <= n * m; i++) {
        pair<int, int> place = index[i];
        if(!rows[place.first] && !columns[place.second])
            ans++;       
    }

    cout << ans;
    return 0;
}