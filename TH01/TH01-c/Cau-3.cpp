#include <bits/stdc++.h>
using namespace std;


vector<int>A(int n) //Thuật toán Eratosthenes
{
    vector<bool> laSNT(n + 1, true);
    laSNT[0] = laSNT[1] = false;//0 và 1 không phải là số nguyên tố
    for (int i = 2; i * i <= n; i++) {
        if (laSNT[i]) {
            for (int j = i * i; j <= n; j += i)
             {
                laSNT[j] = false;
            }
        }
    }
    vector<int> snt;
    for (int i = 2; i <= n; i++) {
        if (laSNT[i]) snt.push_back(i);
    }
    return snt;
}

// Tính số mũ của p trong N!
int somu(int N, int p) {
    int mu = 0;
    while (N > 0) {
        N /= p;
        mu += N;
    }
    return mu;
}

int main() {

    int N;
    while (cin >> N) {  
        vector<int> snt = A(N);
        vector<int> mu;
        for (int p : snt) {
            mu.push_back(somu(N, p));
        }
        
        int last = (int)mu.size() - 1;
        while (last >= 0 && mu[last] == 0) last--;
        for (int i = 0; i <= last; i++) {
            cout << mu[i] << (i == last ? '\n' : ' ');// in ra dãy số mũ của các số nguyên
        }
    }
    return 0;   
}