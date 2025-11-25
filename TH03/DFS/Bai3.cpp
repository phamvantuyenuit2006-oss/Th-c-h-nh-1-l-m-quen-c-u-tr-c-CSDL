#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
using namespace std;

#define FI "Bai3.inp"
#define FO "Bai3.out"

int n;
vector<set<int>> adjlist;
vector<int> color; // -1 = chưa tô, 0 và 1 = 2 màu

bool DFS(int u, int c) {
    color[u] = c;
    for (set<int>::iterator it = adjlist[u].begin(); it != adjlist[u].end(); ++it) {
        int v = *it;
        if (color[v] == -1) {
            if (!DFS(v, 1 - c)) return false;
        } else if (color[v] == c) {
            return false; // mâu thuẫn
        }
    }
    return true;
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
        }
    }

    color.assign(n + 1, -1);

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            if (!DFS(i, 0)) {
                ok = false;
                break;
            }
        }
    }

    if (ok) cout << "Do thi phan doi\n";
    else cout << "Do thi khong phan doi\n";
}

int main() {
    freopen(FI, "rt", stdin);
    freopen(FO, "wt", stdout);
    solve();
    return 0;
}