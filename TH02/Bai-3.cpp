#include <iostream>
#include <vector>
using namespace std;

#define FI "DanhSachKe.inp"
#define FO "DanhSachKe.out"

int n;
vector<vector<int>> adj;
vector<int> deg;

void solve() {
    // Đọc số đỉnh
    cin >> n;
    adj.resize(n + 1);
    deg.assign(n + 1, 0);

    // Đọc danh sách kề cho từng đỉnh
    for (int i = 1; i <= n; i++) {
        while (true) {
            int x;
            cin >> x;
            if (x == -1) break;
            adj[i].push_back(x);
        }
    }

    // Tính bậc cho từng đỉnh
    for (int i = 1; i <= n; i++) {
        deg[i] = adj[i].size();
    }

    // Xuất kết quả
    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cout << deg[i] << endl;
    }
}

int main() {
    freopen(FI, "r", stdin);
    freopen(FO, "w", stdout);
    solve();
    return 0;
}