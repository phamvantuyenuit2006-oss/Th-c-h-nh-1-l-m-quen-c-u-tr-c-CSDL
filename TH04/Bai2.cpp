#include<iostream>
#include<algorithm>
#include<stack>
#include<fstream>
#include<vector>

using namespace std;

#define FI "Bai2.inp"
#define FO "Bai2.out"

int n;
vector<vector<int>> adj(7, vector<int>(7,0));
vector<pair<int,int>>result;

void readInput(ifstream &fi)
{
    fi >> n;
    for (int i=0; i<n;i++)
    {
        int x, y;
        fi>>x>>y;
        adj[x][y]++;
        adj[y][x]++;

    }
}


bool isEuler()
{
    for (int i=0;i<=6;i++)
    {
        int deg=0;
        for(int j=0;j<=6;j++)
        {
            deg+= adj[i][j];

        }
        if (deg %2!=0)
        {
            return false;
        }
    }
    return true;
}

void findEuler(int start)
{
    stack <int> st;
    st.push(start);

    while (!st.empty())
    {
        int u=st.top();
        bool found = false;
        for (int v=0;v<=6;v++)
        {
            if (adj [u][v])
            {
                st.push(v);
                adj[u][v]--;
                adj[v][u]--;
                found = true;
                break;
            }
        }
            if (!found)
            {
                st.pop();
                if(!st.empty())
                {
                    result.push_back({st.top(),u});
                }
            }
    }
}

int main()
{
    ifstream fi(FI);
    ofstream fo(FO);

    readInput(fi);
    int start = -1;
    for (int i = 0; i <= 6; ++i) {
        for (int j = 0; j <= 6; ++j) {
            if (adj[i][j]) {
                start = i;
                break;
            }
        }
        if (start != -1) break;
    }

    findEuler(start);
    for (int i = 0; i <= 6; ++i) {
        for (int j = 0; j <= 6; ++j) {
            if (adj[i][j]) {
                start = i;
                break;
            }
        }
        if (start != -1) break;
    }
     if (result.size() != n) {
        fo << 0 << endl;
    } else {
        fo << 1 << endl;
        for (auto &p : result)
            fo << p.first << " " << p.second << endl;
    }


    fi.close();
    fo.close();
    return 0;
}