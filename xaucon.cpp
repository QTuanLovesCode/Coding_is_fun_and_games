#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
string s;
int pre_1[N], pre_2[N];

bool check_al(char x) {
    return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}

int32_t main(void) 
{
    cin.tie(0)->sync_with_stdio(false);

    freopen("xaucon.inp", "r", stdin);
    freopen("xaucon.out", "w", stdout);

    cin >> s;
    int n = s.size();
    s = '#' + s;

    for(int i = 1; i <= n; i++)
        pre_1[i] = pre_1[i - 1] + check_al(s[i]),
        pre_2[i] = pre_2[i - 1] + (!check_al(s[i]));

    // for(int i = 1; i <= n; i++)
    //     cout << pre_1[i] << ' ';
    // cout << '\n';
    // for(int i = 1; i <= n; i++)
    //     cout << pre_2[i] << ' ';
    // cout << '\n';

    long long ans = 0;
    for(int i = 1; i <= n; i++) 
        ans += (check_al(s[i]) ? pre_2[n] - pre_2[i] : pre_1[n] - pre_1[i]);

    cout << ans;
    return 0;
}