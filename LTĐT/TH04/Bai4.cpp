#include <iostream>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

#define FI "Bai4.inp"
#define FO "Bai4.out"

vector<vector<int>>adj;
vector<bool> visited;
vector<int>hamilton;
int n;

bool backtrack(int pos) {
    if (hamilton.size() == n) {
        if (adj[hamilton.back()][hamilton[0]] == 1) {
            hamilton.push_back(hamilton[0]); 
            return true;
        }
        return false;
    }

    for (int v = 0; v < n; ++v) {
        if (adj[pos][v] == 1 && !visited[v]) {
            visited[v] = true;
            hamilton.push_back(v);
            if (backtrack(v)) return true;
            visited[v] = false;
            hamilton.pop_back();
        }
    }
    return false;
}

int main()
{
    ifstream fi(FI);
    ofstream fo(FO);

    fi >> n;
    adj.assign(n, vector<int>(n));
    visited.assign(n, false);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fi >> adj[i][j];

    visited[0] = true;
    hamilton.push_back(0);

    if (backtrack(0)) {
        fo << 1 << "\n";
        for (int v : hamilton)
            fo << v + 1 << " "; 
        fo << "\n";
    } else {
        fo << 0 << "\n";
    }

    fi.close();
    fo.close();
    return 0;
}


 