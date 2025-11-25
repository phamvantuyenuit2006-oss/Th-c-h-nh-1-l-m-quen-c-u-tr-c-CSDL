#include <iostream>
#include<vector>
#include<string>

using namespace std;
int debai(const string &s) {
    int n = s.size();
   
    
    
 
    const int SIZE = 26 * 26 * 26; // tổng số phần tử bộ ba là 17576
    vector<int> tansuat(SIZE, 0);
    int kq = 0;

    for (int i = 0; i <= n - 3; i++) {
        int a = s[i]   - 'A';
        int b = s[i+1] - 'A';
        int c = s[i+2] - 'A';
        int idx = (a * 26 + b) * 26 + c;
        kq = max(kq, ++tansuat[idx]);
    }
    return kq;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << debai(s) << "\n";
    }
    return 0;
}
