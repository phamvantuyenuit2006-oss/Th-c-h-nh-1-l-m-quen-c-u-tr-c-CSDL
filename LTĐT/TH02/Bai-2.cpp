#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#define FI "MATRANKE.INP"
#define FO "Bacbaobacra.OUT"
int n;
vector<vector<int>> a;
vector<int> hori;
vector<int> verti;

void solve(ofstream& fo){
    // Nhap ma tran ke
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++){
        a[i].resize(n);
        for(int j=0;j<n; j++){
            cin >> a[i][j];
        }
    }

verti.resize(n);
hori.resize(n);


for (int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
hori[i]+=a[i][j];// Tính số bậc ra
verti[j]+=a[i][j]; // Tính số bậc vào
    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << verti[i] << "  " << hori[i] << endl;
    }
}




int main() {
      freopen(FI, "r", stdin);
         ofstream fo(FO);    
    solve(fo);
    fo.close();
    return 0;
}