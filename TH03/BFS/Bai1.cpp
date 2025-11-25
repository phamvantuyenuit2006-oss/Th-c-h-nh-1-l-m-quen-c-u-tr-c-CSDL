#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

#define FI "Bai1.inp"
#define FO "Bai1.out"

int n, x;
vector<set<int>> adjlist;
vector<bool> visited;
deque<int> open;
vector<int> parent;

int BFS(int s){
    int cnt = 0;

    // khoi tao
    fill(visited.begin(), visited.end(), false);
    fill(parent.begin(), parent.end(), -1);
    open.clear();

    // init
    open.push_back(s);
    visited[s] = true;
    while (!open.empty()) {
        cnt = cnt + 1;
        int u = open.front();
        open.pop_front();
        for(set<int>::iterator it = adjlist[u].begin(); 
            it != adjlist[u].end(); it++){
            int v = *it;
            if(visited[v] == false){
                visited[v] = true;
                parent[v] = u;
                open.push_back(v);
            }
        }
    }
    return cnt;
}

void solve(){
    char line[1000];
    stringstream sline;
    int v;

    // doc do thi tu danh sach ke
    cin >> n >> x;
    cin.ignore(1000, '\n');
    // printf("n = %d, x = %d", n, x);
    
    adjlist.resize(n + 1);
    for(int i=1; i<=n; i++){
        cin.getline(line, 1000);
        
        stringstream sline(line);
        while(sline >> v){
            // cout << v << " ";
            adjlist[i].insert(v);
        }
        // cout << endl;
    }

    visited.resize(n + 1);
    open.resize(n + 1);
    parent.resize(n + 1);

    int cnt = BFS(x);
    cout << cnt - 1 << endl;
    for(int u=1; u<=n; u++){
        if(visited[u]==true && u != x)
            cout << u << " ";
    }
    cout << endl;
}

int main(){
    freopen(FI, "rt", stdin);
    freopen(FO, "wt", stdout);
    solve();
    return 0;
}