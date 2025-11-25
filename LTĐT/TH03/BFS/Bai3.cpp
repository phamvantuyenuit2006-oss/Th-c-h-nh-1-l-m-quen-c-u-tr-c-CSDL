#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
using namespace std;

#define FI "Bai3.inp"
#define FO "Bai3.out"

int n;
vector<set<int>> adjlist;
vector<bool> visited;
deque<int> open;

// BFS trả về một thành phần liên thông
vector<int> BFS(int s) {
    vector<int> component;
    open.clear();

    visited[s] = true;
    open.push_back(s);

    while (!open.empty()) {
        int u = open.front();
        open.pop_front();
        component.push_back(u);

        for (set<int>::iterator it = adjlist[u].begin();
             it != adjlist[u].end(); ++it) {
            int v = *it;
            if (!visited[v]) {
                visited[v] = true;
                open.push_back(v);
            }
        }
    }
    return component;
}

void solve() {
    char line[1000];
    int v;

    cin >> n;
    cin.ignore(1000, '\n');

    adjlist.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin.getline(line, 1000);
        stringstream sline(line);
        while (sline >> v) {
            adjlist[i].insert(v);
            adjlist[v].insert(i); // đồ thị vô hướng
        }
    }

    visited.assign(n + 1, false);

    vector<vector<int>> components;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> comp = BFS(i);
            components.push_back(comp);
        }
    }

    cout << components.size() << "\n";
    for (auto &comp : components) {
        for (int u : comp) cout << u << " ";
        cout << "\n";
    }
}

int main() {
    freopen(FI, "rt", stdin);
    freopen(FO, "wt", stdout);
    solve();
    return 0;
}