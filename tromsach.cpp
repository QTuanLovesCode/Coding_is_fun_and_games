#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, m, s;
long long Weight, Time, ans;
pair<int, int> a[N], b[N];
vector<pair<long long, long long>> g1, g2;

void ql(int i, int n, pair<int, int> a[N], vector<pair<long long, long long>> &g){
    if(i > n){
        g.push_back({Weight, Time});
    }
    else {
        for(int j = 0; j <= 1; j++){
            if(j == 1) Weight += a[i].first, Time += a[i].second;
            ql(i + 1, n, a, g);
            if(j == 1) Weight -= a[i].first, Time -= a[i].second;
        }
    }
}

signed main()
{
    cin.tie(0) -> sync_with_stdio(false);

    cin >> n >> s;
    m = n - n / 2;
    n /= 2;
    for(int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for(int i = 1; i <= m; i++) cin >> b[i].first >> b[i].second;

    ql(1, n, a, g1), ql(1, m, b, g2);

//    for(int i = 0; i < g1.size(); i++) cout << g1[i].first << ' ' << g1[i].second << '\n';
//    for(int i = 0; i < g2.size(); i++) cout << g2[i].first << ' ' << g2[i].second << '\n';

    sort(begin(g1), end(g1), [&] (pair<long long, long long> &a, pair<long long, long long> &b){
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

//    for(int i = 0; i < g1.size(); i++) cout << g1[i].first << ' ' << g1[i].second << '\n';

    vector<long long> pre(g1.size());
    pre[0] = g1[0].second;

    for(int i = 1; i < g1.size(); i++) pre[i] = max(pre[i - 1], g1[i].second);

    for(pair<long long, long long> x : g2){
        int l = 0, r = g1.size() - 1, temp = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(g1[mid].first + x.first <= s){
                temp = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        if(temp != -1) ans = max(ans, x.second + pre[temp]);
    }

    cout << ans;
    return 0;
}
