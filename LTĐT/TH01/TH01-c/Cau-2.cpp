#include <bits/stdc++.h>
using namespace std;

int main() {
    

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    set<int> st(A.begin(), A.end());

    // Điều kiện 1: phải đủ N phần tử khác nhau
    if ((int)st.size() != N) {
        cout << "NO\n";
        return 0;
    }

    //xét các số phải nằm trong đoạn từ 1 đến N
    for (int x : st) {
        if (x < 1 || x > N) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}