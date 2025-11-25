#include <iostream>
#include <vector>
using namespace std;

#define FI "MATRANKE.inp"

int n;
vector<vector<int>> a;
vector<int> deg;

void solve(){
    // Nhap ma tran ke
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++){
        a[i].resize(n);
        for(int j=0;j<n; j++){
            cin >> a[i][j];
        }
    }

    deg.resize(n);
    for(int i=0; i<n; i++){
        int degi = 0;   
        for(int j=0;j<n; j++){
            degi = degi + a[i][j];
        }
        deg[i] = degi;
    }

    // in ket qua
    cout << n << endl;
    for(int i=0; i<n; i++){
        cout << deg[i] << endl;
    }
}

int main() {
      freopen(FI, "r", stdin);
    solve();
    return 0;
}