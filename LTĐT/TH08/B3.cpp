#include <bits/stdc++.h>
#define REP(i, n) for (int i = 1; i <= n; i++)

#define pb push_back

#define vi vector<int>
using namespace std;

vi ar[100001];
bool vis[100001];
int color[100001];

bool dfs(int node, int c)
{
    vis[node] = true;
    color[node] = c;

    for (int v : ar[node])
    {
        if (vis[v] == false)
        {
            bool res = dfs(v, c ^ 1);
            if (res == false)
                return false;
        }
        else
        {
            if (color[node] == color[v])
                return false;
        }
    }

    return true;
}

int main()
{
    int a, b, n, m;
    cin >> n >> m;

    REP(i, m)
        cin >> a >> b,
        ar[a].pb(b), ar[b].pb(a);

    bool flag = true;

    REP(i, n)
    if (vis[i] == false)
    {
        flag = dfs(i, 0);
        if (flag == false)
            break;
    }

    if (!flag)
        cout << "IMPOSSIBLE";
    else
        REP(i, n)
            cout << color[i] + 1 << " ";
    
   
}


//code của results đề

// #include <iostream>
// #include <vector>
// using namespace std;

// const int N = 100001;
// vector<int> graph[N];
// int teams[N];

// // The return value indicates whether the team assignments were successful
// bool dfs(int x, int team) {
//     if (teams[x] != 0) return teams[x] == team;
//     teams[x] = team;
//     for (int y : graph[x]) {
//         if (!dfs(y, 3 - team)) return false;
//     }
//     return true;
// }

// int main() {
//     int n, m;
//     cin >> n >> m;

//     for (int i = 0; i < m; ++i) {
//         int a, b;
//         cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     for (int i = 1; i <= n; ++i) {
//         if (teams[i] != 0) continue;
//         if (!dfs(i, 1)) {
//             cout << "IMPOSSIBLE\n";
//             return 0;
//         }
//     }

//     for (int i = 1; i <= n; ++i) {
//         cout << teams[i] << ' ';
//     }
//     cout << '\n';
// }