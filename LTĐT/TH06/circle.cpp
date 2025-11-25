
#include <iostream>
#include <queue>
#include <climits>
#include <stack>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;

#define FI "test.inp"
#define FO "test.out"

struct Circle // Cấu trúc hình tròn
{
    int x, y, r;
};

const int MAXN = 1005;
vector<pair<int, int>> adj[MAXN]; // chứa dsk
int dist[MAXN], trace[MAXN], nhay[MAXN];
bool visited[MAXN];

int n, s, t;

Circle circles[MAXN];

double khoangcach(int i, int j)
{
    double dx = circles[i].x - circles[j].x;
    double dy = circles[i].y - circles[j].y;
    return sqrt(dx * dx + dy * dy) - (circles[i].r + circles[j].r); // tính khoảng cách
}

void buildGraph() // quy đổi thành trọng số
{
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            double d = khoangcach(i, j);
            if (d <= 50) // nếu là bước thì trọng số là 0
            {
                adj[i].emplace_back(j, 0);
                adj[j].emplace_back(i, 0);
            }
            else if (d <= 60) // nếu là nhảy thì trọng số là 1
            {
                adj[i].emplace_back(j, 1);
                adj[j].emplace_back(i, 1);
            }
        }
    }
}

void dijkstra(int s)
{
    for (int i = 1; i <= n; ++i)
    {
        dist[i] = INT_MAX;
        nhay[i] = INT_MAX;
        trace[i] = -1;
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // thay pair thành tuple
    dist[s] = 0;
    nhay[s] = 0;
    pq.emplace(0, 0, s); // (số lần nhảy, số hình tròn, điểm bắt đầu)

    while (!pq.empty())
    {
        auto [jump, step, u] = pq.top();
        pq.pop();

        if (jump > dist[u] || step > nhay[u])
            continue;

        for (auto [v, cost] : adj[u])
        {
            int nhayMoi = jump + cost;
            int buocMoi = step + 1;

            if (nhayMoi < dist[v] || (nhayMoi == dist[v] && buocMoi < nhay[v]))
            {
                dist[v] = nhayMoi;
                nhay[v] = buocMoi;
                trace[v] = u;
                pq.emplace(nhayMoi, buocMoi, v);
            }
        }
    }
}

int main()
{
    ifstream fi(FI);
    fi >> n >> s >> t;
    for (int i = 1; i <= n; ++i)
    {
        fi >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    buildGraph();
    dijkstra(s);

    if (dist[t] == INT_MAX)
    {
        cout << "0\n";
    }
    else
    {
        cout << "1\n";
        cout << dist[t] << " " << nhay[t] + 1 << "\n"; // +1 vì tính cả điểm đầu

        vector<pair<int, int>> path;
        while (t != -1)
        {
            int prev = trace[t];
            int cost = -1;
            if (prev != -1)
            {
                for (auto [v, c] : adj[prev])
                {
                    if (v == t)
                    {
                        cost = c;
                        break;
                    }
                }
            }
            path.emplace_back(t, cost);
            t = prev;
        }

        reverse(path.begin(), path.end());
        for (auto [id, c] : path)
        {
            if (c != -1)
                cout << id << " " << c << "\n";
        }
    }

    return 0;
}