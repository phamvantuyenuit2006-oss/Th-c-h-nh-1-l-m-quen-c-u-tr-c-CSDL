#include <bits/stdc++.h>
using namespace std;

int main() {
    
    const int MAXV = 10000;
    vector<int> cnt(MAXV + 1, 0);

    int nx, ny, nz;
    cin >> nx;
    for (int i = 0; i < nx; i++) {
        int v; cin >> v;
        cnt[v] =1; 
    }

    cin >> ny;
    for (int i = 0; i < ny; i++) {
        int v; cin >> v;
        cnt[v] |= 2; 
    }

    cin >> nz;
    for (int i = 0; i < nz; i++) {
        int v; cin >> v;
        cnt[v] |= 4; 
    }

    vector<int> result;
    for (int v = 0; v <= MAXV; v++) {
        if (cnt[v] == 7) { 
            result.push_back(v);
        }
    }

    cout << result.size() << "\n";
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << (i + 1 == (int)result.size() ? '\n' : ' ');
    }

    return 0;
}