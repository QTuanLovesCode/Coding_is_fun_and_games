#include <bits/stdc++.h>
using namespace std;

long long a, n;

int32_t main(void) 
{
    cin.tie(0)->sync_with_stdio(false);

    // freopen("matma.inp", "r", stdin);
    // freopen("matma.out", "w", stdout);

    cin >> a >> n;
    a %= 10;

    // cout << a << '\n';

    if(a == 0 || a == 1 || a == 5 || a == 6)
        cout << a;
    else  {
        n %= ((a == 2 || a == 3 || a == 7 || a == 8) ? 4 : 2);
        int ans = 1;
        // cout << n << '\n';
        for(int i = 1; i <= (n == 0 ? 4 : n); i++)
            ans *= a;

        ans %= 10;
        cout << ans;
    }
        
    return 0;
}