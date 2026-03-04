#include <bits/stdc++.h>
using namespace std;

#pragma region Dynamic Programming
/// Dynamic Programming (DP)

    #pragma region DP Knapsack
// DP Knapsack (DP cái túi)
// void dp_knapsack()
// {
    // https://oj.vnoi.info/problem/atcoder_dp_d
//     int n, W;
//     cin >> n >> W;
//     vector<pair<int, long long>> a(n + 1);
//     vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, -1e18));
//     for (int i = 1; i <= n; i++)
//         cin >> a[i].first >> a[i].second;

//     dp[0][0] = 0;
//     for (int i = 1; i <= n; i++) {
//         for (int j = 0; j <= W; j++) {
//             dp[i][j] = dp[i - 1][j];
//             if (j - a[i].first >= 0)
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].first] + a[i].second);
//         }
//     }

//     cout << *max_element(begin(dp[n]), end(dp[n]));
// }
#pragma endregion DP Knapsack

    #pragma region DP LIS
    // DP LIS (Dãy con tăng dài nhất)
    /// LIS using Segment Tree
    // void update(vector<int> &st, int id, int l, int r, int pos, int val) {
    //     if(pos > r || pos < l)
    //         return;
    //     if(l == r) {
    //         st[id] = val;
    //         return;
    //     }

    //     int mid = (l + r) >> 1;
    //     update(st, id << 1, l, mid, pos, val);
    //     update(st, id << 1|1, mid + 1, r, pos, val);

    //     st[id] = max(st[id << 1], st[id << 1|1]);
    // }

    // int get(vector<int> &st, int id, int l, int r, int u, int v) {
    //     if(u > r || v < l)
    //         return 0;
    //     if(u <= l && r <= v)
    //         return st[id];

    //     int mid = (l + r) >> 1;
    //     return max(get(st, id << 1, l, mid, u, v), get(st, id << 1|1, mid + 1, r, u, v));
    // }

    /// LIS using Fenwich Tree/BIT (Binary Index Tree)
    // struct FenwichTree {
    //     int size;
    //     vector<int> bit;
    //     FenwichTree(int n) : size(n), bit(n + 1, 0) {}

    //     void update(int pos, int val) {
    //         for (; pos <= size; pos += pos & (-pos))
    //             bit[pos] = max(bit[pos], val);
    //     }

    //     int get(int pos) {
    //         int ans = 0;
    //         for (; pos >= 1; pos -= pos & (-pos)) {
    //             ans = max(ans, bit[pos]);
    //         }

    //         return ans;
    //     }
    // };

    // void dp_LIS()
    // {
        // https://oj.vnoi.info/problem/liq
        // int n;
        // cin >> n;
        // vector<long long> a(n + 1), dp(n + 1);
        // for (int i = 1; i <= n; i++)
        //     cin >> a[i];


        // for (int i = 1; i <= n; i++) {
        //     dp[i] = 1;
        //     for (int j = 1; j < i; j++) {
        //         if(a[i] > a[j])
        //             dp[i] = max(dp[i], dp[j] + 1);
        //     }
        // }

        // cout << *max_element(begin(dp) + 1, end(dp)) << '\n';

        // https://oj.vnoi.info/problem/lis (Bản khó)
        // Segment Tree/BIT
        // vector<long long> nen;
        // for (int i = 1; i <= n; i++)
        //     nen.push_back(a[i]);

        // sort(begin(nen), end(nen));
        // nen.erase(unique(begin(nen), end(nen)), end(nen));
        // int max_a = nen.size();
        // vector<int> st(max_a << 2), Dp(max_a + 1);
        // FenwichTree ft(max_a);
        // for (int i = 1; i <= n; i++) {
        //     int new_a = lower_bound(begin(nen), end(nen), a[i]) - begin(nen) + 1;
        //     Dp[new_a] = max(Dp[new_a], get(st, 1, 1, max_a, 1, new_a - 1) + 1);
        //     update(st, 1, 1, max_a, new_a, Dp[new_a]);
        //     int dp_i = ft.get(new_a - 1) + 1;
        //     ft.update(new_a, dp_i);
        // }

        // cout << st[1] << '\n';
        // cout << ft.get(max_a) << '\n';

        // Binary search 
    //     vector<long long> b(n + 1);
    //     int Max = 0;
    //     for (int i = 1; i <= n; i++) {
    //         int j = lower_bound(begin(b) + 1, begin(b) + 1 + Max, a[i]) - begin(b) - 1;
    //         b[j + 1] = a[i];
    //         Max = max(Max, j + 1);
    //     }

    //     cout << Max;
    // }
    #pragma endregion DP LIS

    #pragma region DP LCS
    /// DP_LCS (Longest Common Subsequence)
    // string a, b;
    // int dp[(int) 2e3 + 5][(int) 2e3 + 5];

    // void dp_LCS()
    // {
        // https://oj.vnoi.info/problem/qbstr
    //     cin >> a >> b;
    //     int n = a.size(), m = b.size();
    //     a = '#' + a;
    //     b = '.' + b;

    //     for (int i = 1; i <= n; i++)
    //         dp[i][0] = 0;
    //     for (int j = 1; j <= m; j++)
    //         dp[0][j] = 0;
        
    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= m; j++) {
    //             if(a[i] == b[j])
    //                 dp[i][j] = dp[i - 1][j - 1] + 1;
    //             else 
    //                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }

    //     cout << dp[n][m];
    // }
    #pragma endregion DP LIS

    #pragma region DP Grid
/// DP trên lưới
// void dp_grid()
// {
    // https://cses.fi/problemset/task/1638/
//     const int mod = 1e9 + 7;
//     int n;
//     cin >> n;
//     vector<vector<char>> a(n + 1, vector<char>(n + 1));
//     vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//             cin >> a[i][j];
    
//     dp[1][1] = (a[1][1] == '.');
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             if(a[i][j] == '*')
//                 continue;
//             if(a[i][j] == '.') {
//                 if(i > 1)
//                     (dp[i][j] += (dp[i - 1][j] % mod)) %= mod;
//                 if(j > 1)
//                     (dp[i][j] += (dp[i][j - 1] % mod)) %= mod;
//             }
//         }
//     }
    
//     cout << dp[n][n] % mod;
// }
#pragma endregion DP Grid
#pragma endregion Dynamic Programming

#pragma region Greedy
/// Interval Scheduling Problem (Greedy)
// void ISP()
// {
    // https://cses.fi/problemset/task/1629/
//     int n;
//     cin >> n;
//     vector<pair<long long, long long>> a(n + 1);

//     for (int i = 1; i <= n; i++)
//         cin >> a[i].first >> a[i].second;

//     sort(begin(a) + 1, end(a), [&] (const pair<long long, long long> &a, const pair<long long, long long> &b) {
//         return a.second < b.second;
//     });

//     int index = 1, movies = 0;
//     long long last_pos = -1;

//     while (index <= n) {
//         if(a[index].first >= last_pos)
//             movies++, 
//             last_pos = a[index].second;
//         index++;
//     }

//     cout << movies;
// }
#pragma endregion Greedy

#pragma region Binary Search
/// Binary Search on answers
// int n, k;
// long long x[(int) 2e5 + 5];

// bool check(long long mid) {
//     long long cur_sum = 0;
//     int sub = 1;
//     for (int i = 1; i <= n; i++) {
//         if(x[i] > mid)
//             return false;
//         if(cur_sum + x[i] > mid) 
//             sub++,
//             cur_sum = x[i];
//         else 
//             cur_sum += x[i];
//     }

//     return sub <= k;
// }

// void BS_ArrayDivision()
// {
    // https://cses.fi/problemset/task/1085/
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//         cin >> x[i];

//     long long l = *max_element(x + 1, x + 1 + n), r = accumulate(x + 1, x + 1 + n, 0ll), ans = 0;
//     while (l <= r) {
//         long long mid = (l + r) >> 1;
//         if(check(mid)) {
//             ans = mid;
//             r = mid - 1;
//         }

//         else 
//             l = mid + 1;
//     }

//     cout << ans;
// }

// int n;
// long long t, a[(int) 2e5 + 5];

// bool check(long long x) {
//     long long machines = 0;
//     for (int i = 1; i <= n; i++) {
//         machines += x / a[i];
//         if(machines >= t)
//             return true;
//     }

//     return machines >= t;
// }

// void BS_FactoryMachines()
// {
    // https://cses.fi/problemset/task/1620/
//     cin >> n >> t;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i];

//     long long l = 0, r = *max_element(a + 1, a + 1 + n) * t, ans = -1;
//     while (l <= r) {
//         long long mid = (l + r) >> 1;
//         if(check(mid)) 
//             ans = mid,
//             r = mid - 1;
//         else 
//             l = mid + 1;
//     }

//     cout << ans;
// }
#pragma endregion Binary Search

#pragma region Number Theory
/// Number Theory
    #pragma region Prime numbers
    // Prime Numbers
    // Eratosthenes Sieve
    // const int N = 2e4;
    // bool snt[N + 5];
    // vector<int> primes;
    // vector<long long> pre;

    // void era()
    // {   
    //     fill(snt + 2, snt + 1 + N, true);
    //     for (int i = 2; i * i <= N; i++)
    //         if(snt[i])
    //             for (int j = i * i; j <= N; j += i)
    //                 snt[j] = false;

    //     primes.push_back(0);
    //     for (int i = 2; i <= 11000; i++)
    //         if(snt[i])
    //             primes.push_back(i);

    //     pre.resize(primes.size());
    //     for (int i = 1; i < primes.size(); i++)
    //         pre[i] = pre[i - 1] + primes[i];
    // }

    // int present(int x) {
    //     int ans = 0;
    //     for (int i = 1; i < primes.size() && primes[i] <= x; i++) {
    //         if(pre[i] < x)
    //             continue;
    //         int l = 1, r = i;
    //         while (l <= r) {
    //             int mid = (l + r) >> 1;
    //             if(pre[i] - pre[mid - 1] == x) {
    //                 ans++;
    //                 break;
    //             }
                
    //             else if(pre[i] - pre[mid - 1] < x)
    //                 r = mid - 1;
    //             else 
    //                 l = mid + 1;
    //         }
    //     }

    //     return ans;
    // } 

    // void Sum_of_Primes()
    // {
        // https://oj.vnoi.info/problem/mprime1
    //     era();
    //     int x;
    //     while (cin >> x) {
    //         if(x == 0)
    //             exit(0);
            
    //         cout << present(x) << '\n';
    //     }
    // }

    // Segmented Sieve
    // void Prime1()
    // {
        // https://www.spoj.com/problems/PRIME1/
    //     int test;
    //     cin >> test;

    //     while (test--) {
    //         long long l, r;
    //         cin >> l >> r;
    //         vector<bool> primes(r - l + 2);
    //         fill(begin(primes), end(primes), true);
    //         for (long long i = 2; i <= sqrt(r); i++) 
    //             for (long long j = max(i * i, (l + i - 1) / i * i); j <= r; j += i)
    //                 primes[j - l] = false;
            
    //         for (long long i = max(2ll, l); i <= r; i++)
    //             if(primes[i - l])
    //                 cout << i << '\n';
                
    //         cout << '\n';
    //     }
    // }
    #pragma endregion Prime numbers

    #pragma region Prime factorization
    // Prime Factorization (Phân tích thừa số nguyên tố)
    // string change(int x) {
    //     string res = "";
    //     while (x > 0)
    //         res += (x % 10 + '0'),
    //         x /= 10;

    //     reverse(begin(res), end(res));
    //     return res;
    // }

    // void Prime_factor()
    // {
        // https://lqdoj.edu.vn/problem/24ct0402primefactor
    //     int test;
    //     cin >> test;

    //     while (test--) {
    //         int x;
    //         cin >> x;
    //         vector<pair<int, int>> factor;
    //         int t = x;
    //         for (int i = 2; i <= sqrt(x); i++) {
    //             if(t % i == 0) {
    //                 int cnt = 0;
    //                 while (t % i == 0)
    //                     t /= i,
    //                     cnt++;
                    
    //                 factor.push_back({i, cnt});
    //             }
    //         }

    //         if(t != 1)
    //             factor.push_back({t, 1});

    //         string res = "";
    //         for (auto [nt, mu] : factor) {
    //             res += change(nt);
    //             if(mu > 1)
    //                 res += '^',
    //                 res += change(mu);

    //             res += '*';
    //         }

    //         for (int i = 0; i < res.size() - 1; i++)
    //             cout << res[i];
    //         cout << '\n';
    //     }
    // }
    #pragma endregion Prime factorization

    #pragma region Binary Exponentation
    // Binary Exponentation
    // long long Pow(long long a, long long b) {
    //     if(!b)
    //         return 1;
    //     long long x = Pow(a, b / 2);
    //     if(b % 2 == 0)
    //         return x * x;
    //     return x * x * a;
    // }
    #pragma endregion Binary Exponentation

    #pragma endregion Number Theory

#pragma region Graphs
/// Graphs

    #pragma region DFS
    // DFS (Depth-First Search)
    // int n, m;
    // const int N = 5e3 + 5;
    // vector<int> adj[N], path;
    // bool visited[N];

    // void dfs(int u)
    // {
    //     visited[u] = true;
    //     path.push_back(u);

    //     for (int v : adj[u]) {
    //         if(!visited[v]) 
    //             dfs(v);
    //     }
    // }

    // void dfs_of_graph()
    // {
        // https://vn.spoj.com/CHUYENSL/problems/DFSDEMO/
    //     cin >> n >> m;

    //     path.clear();
    //     for (int i = 1; i <= n; i++)
    //         adj[i].clear(),
    //         visited[i] = false;
    //     for (int i = 1; i <= m; i++) {
    //         int u, v;
    //         cin >> u >> v;
    //         adj[u].push_back(v);
    //         adj[v].push_back(u);
    //     }

    //     for (int i = 1; i <= n; i++)
    //         sort(begin(adj[i]), end(adj[i]));

    //     dfs(1);
    //     for (int x : path)
    //         cout << x << '\n';
    // }
    #pragma endregion DFS

    #pragma region BFS
    // BFS (Breadth-First Search)
    // const int N = 2e5 + 5, INF = 1e9;
    // int n, m, s, t, dist[N];
    // vector<int> adj[N];

    // void bfs()
    // {
    //     fill(dist + 1, dist + 1 + n, INF);
    //     dist[s] = 0;
    //     queue<int> q;
    //     q.push(s);

    //     while(!q.empty()) {
    //         int u = q.front();
    //         q.pop();

    //         for (int v : adj[u]) {
    //             if(dist[v] > dist[u] + 1) {
    //                 dist[v] = dist[u] + 1;
    //                 q.push(v);
    //             }
    //         }
    //     }

    //     cout << (dist[t] == INF ? -1 : dist[t]);
    // }

    // void bfs_vohuong()
    // {
        // https://codeforces.com/group/yHWqtSfEA2/contest/405649/problem/C
    //     cin >> n >> m >> s >> t;
    //     for (int i = 1; i <= m; i++) {
    //         int x, y;
    //         cin >> x >> y;
    //         adj[x].push_back(y);
    //         adj[y].push_back(x);
    //     }

    //     bfs();
    // }   

    #pragma region BFS Matrix
    // bfs matrix
    // const int N = 1e2 + 5, INF = 1e9,
    // dx[] = {1, 0, -1, 0},
    // dy[] = {0, 1, 0, -1};
    // int r, c, dist[N][N];
    // pair<int, int> start;
    // char a[N][N];

    // bool check_matrix(int i, int j, int x, int y) {
    //     return i >= 1 && i <= r && j >= 1 && j <= c && a[i][j] != '*' && dist[i][j] > dist[x][y] + 1;
    // }

    // void bfs_2d()
    // {
    //     for (int i = 1; i <= r; i++)
    //         for (int j = 1; j <= c; j++)
    //             dist[i][j] = INF;

    //     dist[start.first][start.second] = 0;
    //     queue<pair<int, int>> q;
    //     q.push(start);

    //     while(!q.empty()) {
    //         int u = q.front().first,
    //             v = q.front().second;
    //         q.pop();

    //         for (int s = 0; s < 4; s++) {
    //             int x = u + dx[s],
    //                 y = v + dy[s];

    //             if(check_matrix(x, y, u, v)) {
    //                 dist[x][y] = dist[u][v] + 1;
    //                 q.push({x, y});
    //             }
    //         }
    //     }

    //     cout << (dist[1][1] == INF ? -1 : dist[1][1]);
    // }

    // void bfs_matrix()
    // {
        // https://codeforces.com/group/yHWqtSfEA2/contest/405649/problem/G
    //     cin >> r >> c;
    //     for (int i = 1; i <= r; i++) {
    //         for (int j = 1; j <= c; j++) {
    //             cin >> a[i][j];
    //             if(a[i][j] == 'C')
    //                 start = {i, j};
    //         }
    //     }

    //     bfs_2d();
    // }
    #pragma endregion BFS Matrix

    #pragma region BFS-01
    // BFS-01
    // const int INF = 1e9,
    // dx[] = {1, 0, -1, 0},
    // dy[] = {0, 1, 0, -1};

    // void bfs_deque(int n, int m, vector<vector<char>> &a)
    // {
    //     vector<vector<int>> dist(n + 1, vector<int>(m + 1));
    //     for (int i = 1; i <= n; i++)
    //         for (int j = 1; j <= m; j++)
    //             dist[i][j] = INF;

    //     dist[1][1] = 0;
    //     deque<pair<int, int>> dq;
    //     dq.push_back({1, 1});

    //     while (!dq.empty()) {
    //         int u = dq.front().first,
    //             v = dq.front().second;

    //         char cur = a[u][v];
    //         dq.pop_front();
    //         for (int s = 0; s < 4; s++) {
    //             int x = u + dx[s],
    //                 y = v + dy[s];

    //             if(x > 0 && x <= n && y > 0 && y <= m) {
    //                 int cost = (cur == a[x][y] ? 0 : 1);
    //                 if(dist[x][y] > dist[u][v] + cost) {
    //                     dist[x][y] = dist[u][v] + cost;
    //                     if(cost == 0)
    //                         dq.push_front({x, y});
    //                     else 
    //                         dq.push_back({x, y});
    //                 }
    //             }
    //         }
    //     }

    //     cout << dist[n][m] << '\n';
    // }

    // void bfs_01()
    // {
        // https://vn.spoj.com/problems/KATHTHI/
    //     int test;
    //     cin >> test;

    //     while (test--) {
    //         int n, m;
    //         cin >> n >> m;
    //         vector<vector<char>> a(n + 1, vector<char>(m + 1));
    //         for (int i = 1; i <= n; i++) 
    //             for (int j = 1; j <= m; j++)
    //                 cin >> a[i][j];

    //         bfs_deque(n, m, a);
    //     }
    // }
    #pragma endregion BFS-01

    #pragma region BFS multidirectional
    // BFS multidirectional
    // const int INF = 1e9,
    // dx[] = {1, 0, -1, 0},
    // dy[] = {0, 1, 0, -1};

    // void bfs_multi(int n, int m, vector<vector<char>> &a, queue<pair<int, int>> &start, vector<vector<int>> &dist) {
    //     while (!start.empty()) {
    //         int u = start.front().first,
    //             v = start.front().second;
            
    //         start.pop();
    //         for (int s = 0; s < 4; s++) {
    //             int x = u + dx[s], 
    //                 y = v + dy[s];
                
    //             if(x > 0 && x <= n && y > 0 && y <= m && dist[x][y] > dist[u][v] + 1) {
    //                 dist[x][y] = dist[u][v] + 1;
    //                 start.push({x, y});
    //             }
    //         }
    //     }

    //     for (int i = 1; i <= n; i++) {
    //         for (int j = 1; j <= m; j++)
    //             cout << dist[i][j] << ' ';
    //         cout << '\n';
    //     }

    //     cout << '\n';
    // }

    // void bfs_da_nguon()
    // {
        // https://www.spoj.com/problems/BITMAP/
    //     int test;
    //     cin >> test;

    //     while (test--) {
    //         int n, m;
    //         cin >> n >> m;
    //         vector<vector<char>> a(n + 1, vector<char>(m + 1));
    //         vector<vector<int>> dist(n + 1, vector<int>(m + 1, INF));
    //         queue<pair<int, int>> q;
    //         for (int i = 1; i <= n; i++)
    //             for (int j = 1; j <= m; j++) {
    //                 cin >> a[i][j];
    //                 if(a[i][j] == '1')
    //                     q.push({i, j}),
    //                     dist[i][j] = 0;
    //             }

    //         bfs_multi(n, m, a, q, dist);
    //     }
    // }
    #pragma BFS endregion multidirectional

    #pragma endregion BFS

    #pragma region Dijkstra
    // Dijkstra
    // const int N = 1e5 + 5;
    // const long long INF = 1e18;
    // int n, m;
    // long long dist[N];
    // vector<pair<int, long long>> adj[N];
    // priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    // void dijk()
    // {
    //     fill(dist + 1, dist + 1 + n, INF);
    //     dist[1] = 0;
    //     pq.push({dist[1], 1});

    //     while (!pq.empty()) {
    //         long long cost = pq.top().first,
    //                   u = pq.top().second;
    //         pq.pop();
    //         if(cost > dist[u])
    //             continue;

    //         for (auto v : adj[u]) {
    //             if(dist[v.first] > dist[u] + v.second) {
    //                 dist[v.first] = dist[u] + v.second;
    //                 pq.push({dist[v.first], v.first});
    //             }
    //         }
    //     }

    //     cout << dist[n];
    // }

    // void dijkstra()
    // {
        // https://codeforces.com/group/yHWqtSfEA2/contest/408485/problem/A
    //     cin >> n >> m;
    //     for (int i = 1; i <= m; i++) {
    //         int u, v;
    //         long long c;
    //         cin >> u >> v >> c;
    //         adj[u].push_back({v, c});
    //         adj[v].push_back({u, c});
    //     }

    //     dijk();
    // }

    #pragma region Dijkstra 2D
    // Dijkstra 2D
    // const int N = 5e2 + 5,
    // dx[] = {0, -1, 1},
    // dy[] = {1, 1, 1};
    // const long long INF = 1e18;
    // int n, m;
    // long long a[N][N], dist[N][N];

    // struct graphs {
    //     long long w;
    //     int x, y;
    // };

    // void dijk_2D()
    // {
    //     auto cmp = [&] (const graphs &a, const graphs &b) {
    //         return a.w > b.w;
    //     };

    //     priority_queue<graphs, vector<graphs>, decltype(cmp)> pq(cmp);
    //     for (int i = 1; i <= n; i++) 
    //         for (int j = 1; j <= m; j++)
    //             dist[i][j] = INF;

    //     for (int j = 1; j <= m; j++) {
    //         dist[1][j] = a[1][j];
    //         pq.push({dist[1][j], 1, j});
    //     }

    //     while (!pq.empty()) {
    //         long long cost = pq.top().w;
    //         int u = pq.top().x, 
    //             v = pq.top().y;

    //         pq.pop();
    //         if(cost > dist[u][v])
    //             continue;
            
    //         for (int s = 0; s < 3; s++) {
    //             int x = u + dx[s],
    //                 y = v + dy[s];
                
    //             if(x > 0 && x <= n && y > 0 && y <= m && dist[x][y] > dist[u][v] + a[x][y]) {
    //                 dist[x][y] = dist[u][v] + a[x][y];
    //                 pq.push({dist[x][y], x, y});
    //             }
    //         }
    //     }

    //     long long ans = INF;
    //     for (int j = 1; j <= m; j++)
    //         ans = min(ans, dist[n][j]);

    //     cout << ans;
    // }

    // void dijkstra_2D()
    // {
        // https://codeforces.com/group/yHWqtSfEA2/contest/408485/problem/G
    //     cin >> n >> m;
    //     for (int i = 1; i <= n; i++)
    //         for (int j = 1; j <= m; j++)
    //             cin >> a[i][j];

    //     dijk_2D();
    // }   
    #pragma endregion Dijkstra 2D

    #pragma endregion Dijkstra

    #pragma region DSU
// DSU (Disjoint Set Union)
// const int N = 5e5 + 5;
// int n, q, par[N];

// int acs(int u) {
//     if(par[u] == u)
//         return u;
//     return par[u] = acs(par[u]);
// }

// void join(int x, int y) {
//     int u = acs(x), 
//         v = acs(y);
//     if(u != v)
//         par[u] = v;
// }

// void dsu()
// {
    // https://codeforces.com/group/yHWqtSfEA2/contest/415123/problem/A
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++)
//         par[i] = i;

//     while (q--) {
//         char type;
//         int x, y;
//         cin >> type >> x >> y;

//         if(type == '+') 
//             join(x, y);
//         else 
//             cout << (acs(x) == acs(y) ? "YES\n" : "NO\n");
//     }
// }

#pragma region MST
// MST (Max/Min Spanning Tree)
// const int N = 2e5 + 5; 
// int n, m, par[N];

// struct graphs {
//     int u, v;
//     long long w;
// };

// int acs(int u) {
//     return (par[u] == u ? u : par[u] = acs(par[u]));
// }

// void join(int x, int y) {
//     int u = acs(x),
//         v = acs(y);
    
//     if(u != v)
//         par[u] = v;
// }

// void mst()
// {
    // https://codeforces.com/group/yHWqtSfEA2/contest/412805/problem/A
//     cin >> n >> m;

//     for (int i = 1; i <= n; i++)
//         par[i] = i;
//     vector<graphs> edge(m);
//     for (int i = 0; i < m; i++)
//         cin >> edge[i].u >> edge[i].v >> edge[i].w;

//     sort(begin(edge), end(edge), [&] (const graphs &a, const graphs &b) {
//         return a.w > b.w;
//     });

//     long long ans = 0;
//     for (int i = 0; i < m; i++) {
//         if(acs(edge[i].u) != acs(edge[i].v))
//             ans += edge[i].w,
//             join(edge[i].u, edge[i].v);
//     }

//     cout << ans;
// }
#pragma endregion MST

#pragma endregion DSU

#pragma endregion Graphs

#pragma region Segment Tree 

    #pragma region Seg lazy
    /// Segment Tree (Lazy Propagation)
    // const int N = 1e5 + 5;
    // const long long INF = -1e18;
    // int n, m;
    // long long st[N << 2], lazy[N << 2];

    // void Laze(int id) {
    //     if(lazy[id] != 0) {
    //         long long x = lazy[id];
    //         st[id << 1] += x;
    //         lazy[id << 1] += x;
    //         st[id << 1|1] += x;
    //         lazy[id << 1|1] += x;
    //         lazy[id] = 0;
    //     }
    // }

    // void update(int id, int l, int r, int u, int v, long long val) {
    //     if(u > r || v < l)
    //         return;

    //     if(u <= l && r <= v) {
    //         st[id] += val;
    //         lazy[id] += val;
    //         return;
    //     }

    //     Laze(id);
    //     int mid = (l + r) >> 1;

    //     update(id << 1, l, mid, u, v, val);
    //     update(id << 1|1, mid + 1, r, u, v, val);

    //     st[id] = max(st[id << 1], st[id << 1|1]);
    // }

    // long long get(int id, int l, int r, int u, int v) {
    //     if(u > r || v < l)
    //         return INF;

    //     if(u <= l && r <= v)
    //         return st[id];

    //     Laze(id);
    //     int mid = (l + r) >> 1;
    //     return max(get(id << 1, l, mid, u, v), get(id << 1|1, mid + 1, r, u, v));
    // }

    // void Seg_lazy()
    // {
        // https://codeforces.com/group/yHWqtSfEA2/contest/383770/problem/I
    //     cin >> n >> m;
    //     for (int i = 1; i <= m; i++) {
    //         int type, x, y;
    //         long long k;
    //         cin >> type;
            
    //         if(type == 0) {
    //             cin >> x >> y >> k;
    //             update(1, 1, n, x, y, k);
    //         }

    //         else {
    //             cin >> x >> y;
    //             cout << get(1, 1, n, x, y) << '\n';
    //         }
    //     }
    // }
    #pragma endregion Seg lazy

    #pragma region Walk on Seg
// Walk on Segment Tree
// const int N = 3e5 + 5;
// int n, m;
// long long a[N], st[N << 2];

// void update(int id, int l, int r, int pos, long long val) {
//     if(pos > r || pos < l)
//         return;
//     if(l == r) {
//         st[id] = val;
//         return;
//     }

//     int mid = (l + r) >> 1;
//     update(id << 1, l, mid, pos, val);
//     update(id << 1|1, mid + 1, r, pos, val);

//     st[id] = min(st[id << 1], st[id << 1|1]);
// }

// int walk_left(int id, int l, int r, int u, int v, long long k) {
//     if(u > r || v < l || st[id] > k)
//         return -1;
//     if(l == r)
//         return l;

//     int mid = (l + r) >> 1,
//         ret = walk_left(id << 1, l, mid, u, v, k);

//     if(ret == -1)
//         ret = walk_left(id << 1|1, mid + 1, r, u, v, k);

//     return ret;
// }

// int walk_right(int id, int l, int r, int u, int v, long long k) {
//     if(u > r || v < l || st[id] > k)
//         return -1;
//     if(l == r)
//         return l;

//     int mid = (l + r) >> 1,
//         ret = walk_right(id << 1|1, mid + 1, r, u, v, k);

//     if(ret == -1)
//         ret = walk_right(id << 1, l, mid, u, v, k);

//     return ret;
// }

// void walk_on_seg()
// {
    // https://codeforces.com/group/yHWqtSfEA2/contest/383770/problem/J
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//         cin >> a[i],
//         update(1, 1, n, i, a[i]);

//     while (m--) {
//         int type, pos, l, r;
//         long long k;
//         cin >> type;

//         if(type == 1) {
//             cin >> pos >> k;
//             update(1, 1, n, pos, k);
//         }
        
//         else {
//             cin >> l >> r >> k;
//             cout << walk_left(1, 1, n, l, r, k) << ' ' << walk_right(1, 1, n, l, r, k) << '\n';
//         }
//     }
// }
#pragma endregion Walk on Seg

#pragma endregion Segment Tree

#pragma region String (Hashing)
/// String
// Hashing
// const long long mod = 1e9 + 7, base = 31;

// void Hash()
// {
    // https://oj.vnoi.info/problem/fc058_hash
//     string s;
//     int q;
//     cin >> s >> q;
//     int n = s.size();
//     vector<long long> power(n + 1), hash_s(n + 1);

//     power[0] = 1;
//     for (int i = 1; i <= n; i++)
//         power[i] = (power[i - 1] * base) % mod;
//     s = '#' + s;
//     for (int i = 1; i <= n; i++) 
//         hash_s[i] = (hash_s[i - 1] * base + s[i] - 'a' + 1) % mod;

//     while (q--) {
//         int l, r;
//         cin >> l >> r;
//         cout << ((hash_s[r] - hash_s[l - 1] * power[r - l + 1]) % mod + mod) % mod << '\n';
//     }
// }
#pragma endregion String (Hashing)

#pragma region Stress Testing (Sinh Test)
/// Stress Testing
// mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

// long long Rand(long long l, long long r) {
//     return uniform_int_distribution<long long> (l, r) (rng);
// }

// void sinh()
// {
    // https://cses.fi/problemset/task/1643
//     for (int test = 1; test <= 1e2; test++) {
//         ofstream fout("Max.inp");

//         int n = Rand(1ll, (long long) 1e3);
//         fout << n << endl;

//         for (int i = 1; i <= n; i++) {
//             long long x = Rand((long long) -1e9, (long long) 1e9);
//             fout << x << ' ';
//         }

//         fout.close();

//         system("Max.exe");
//         system("brute.exe");

//         if(system("fc Max.out brute.out")) {
//             cout << "Wrong Answer at test " << test << endl;
//             system("type Max.inp");
//             exit(0);
//         }
//     }

//     cout << "Accepted\n";
// }
#pragma endregion Stress Testing (Sinh Test)

int32_t main(void)
{
    /// Speed up the input/output process
    cin.tie(0)->sync_with_stdio(false);

    /// Input, Output (Nhập/Xuất File, bao gồm sinh test)
    FILE* f = fopen("text.INP", "r");
    if(f) {
        fclose(f);
        freopen("text.INP", "r", stdin);
        freopen("text.OUT", "w", stdout);
    }

    /// Dynamic Programming
    // dp_knapsack();
    // dp_LIS();
    // dp_LCS();
    // dp_grid();

    /// Greedy
    // ISP();

    /// Binary Search on Answers
    // BS_ArrayDivision();
    // BS_FactoryMachines();

    /// Number theory
    // Eratosthenes (Sàng nguyên tố)
    // Sum_of_Primes();
    // Segmented Sieve (Sàng nguyên tố trên đoạn)
    // Prime1();
    // Prime Factorization
    // Prime_factor();

    // / Graphs 
    // DFS
    // dfs_of_graph();

    // BFS
    // bfs_vohuong();
    // BFS Matrix
    // bfs_matrix();
    // BFS-01
    // bfs_01();
    // BFS đa nguồn
    // bfs_da_nguon();

    // Dijkstra
    // dijkstra();
    // Dijk 2D
    // dijkstra_2D();

    // DSU
    // dsu();

    // MST
    // mst();

    /// Data structure
    // Segment Tree - Lazy propagation
    // Seg_lazy();

    // Walk on Segment Tree
    // walk_on_seg();

    /// String 
    // Hashing
    // Hash();

    /// Stress Testing (Sinh Test)
    // sinh();
    return 0;
}