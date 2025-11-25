#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;

#define FI "FILE.inp"
#define FO "Bai2.out"

int n, x, y;
vector<set<int>> adjlist;
vector<bool> visited;
deque<int> open;
vector<int> parent;

int BFS(int s) {
    // khởi tạo
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    open.clear();

    // bắt đầu từ s
    open.push_back(s);
    visited[s] = true;

    while (!open.empty()) {
        int u = open.front();
        open.pop_front();
        for (set<int>::iterator it = adjlist[u].begin(); it != adjlist[u].end(); it++) {
            int v = *it;
            if (visited[v] == false) {
                visited[v] = true;
                parent[v] = u;
                open.push_back(v);
            }
        }
    }
    return 0;
}

void solve() {
    char line[1000];
    int v;

    // đọc đồ thị
    cin >> n >> x >> y;
    cin.ignore(1000, '\n');

    adjlist.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin.getline(line, 1000);
        stringstream sline(line);
        while (sline >> v) {
            adjlist[i].insert(v);
            adjlist[v].insert(i); // vô hướng
        }
    }

    visited.resize(n + 1);
    parent.resize(n + 1);

    BFS(x);

    if (!visited[y]) {
        cout << "-1\n"; // không có đường đi
        return;
    }

    // truy vết đường đi từ y về x
    vector<int> path;
    for (int u = y; u != -1; u = parent[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (int u : path) cout << u << " ";
    cout << endl;
}

int main() {
    freopen(FI, "rt", stdin);
    freopen(FO, "wt", stdout);
    solve();
    return 0;
}