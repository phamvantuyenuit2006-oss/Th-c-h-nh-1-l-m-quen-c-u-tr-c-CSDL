#include <bits/stdc++.h>
using namespace std;

int main() {
  
    long long N;
    while ( (cin >> N) ) {
        long long ans = 0;
        long long t = N;
        while (t > 0) {
            t /= 5;
            ans += t;
        }
        cout << ans << '\n';
    }
    return 0;
}