#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
using namespace std;

#define FI "Bai1.inp"
#define FO "Bai1.out"

int n, x;
vector<set<int>> adjlist;
vector<bool> visited;
vector<int> component; // lưu các đỉnh trong thành phần liên thông với x

void DFS(int u) {
    visited[u] = true;
    component.push_back(u);
    for (set<int>::iterator it = adjlist[u].begin();
         it != adjlist[u].end(); ++it) {
        int v = *it;
        if (!visited[v]) {
            DFS(v);
        }
    }
}

void solve() {
    char line[1000];
    int v;

    cin >> n >> x;
    cin.ignore(1000, '\n');

    adjlist.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin.getline(line, 1000);
        stringstream sline(line);
        while (sline >> v) {
            adjlist[i].insert(v);
        }
    }

    visited.assign(n + 1, false);
    component.clear();

    DFS(x);

   
    vector<int> result;//Không đếm đỉnh x vào
    for (int u : component) {
        if (u != x) result.push_back(u);
    }

    cout << result.size() << "\n";
    for (int u : result) cout << u << " ";
    cout << "\n";
}

int main() {
    freopen(FI, "rt", stdin);
    freopen(FO, "wt", stdout);
    solve();
    return 0;
}