#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define FI "test1.inp"

vector<vector<int>> adj;

int n;

void greedyColoring(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> result(n, -1);
    result[0] = 0;

    vector<bool> available(n, false);

    for (int u = 1; u < n; u++)
    {
        for (int neighbour : adj[u])
        {
            if (result[neighbour] != -1)
            {
                available[result[neighbour]] = true;
            }
        }
        int cr;
        for (cr = 0; cr < n; cr++)
        {
            if (!available[cr])
                break;
        }
        result[u] = cr;

        for (int neighbour : adj[u])
        {
            if (result[neighbour] != -1)
                available[result[neighbour]] = false;
        }
    }
    // Tìm số màu lớn nhất đã dùng
    int maxColor = *max_element(result.begin(), result.end()); //*max_element = tìm phần tử lớn nhất trong thư viện algorithm

    // Tạo danh sách các đỉnh theo từng màu
    vector<vector<int>> colorGroups(maxColor + 1);
    for (int u = 0; u < n; u++)
    {
        colorGroups[result[u]].push_back(u + 1); // +1 để in lại theo chỉ số từ 1
    }

    // In ra kết quả
    cout << maxColor + 1 << endl;
    for (const auto &group : colorGroups)
    {
        for (int v : group)
            cout << v << " ";
        cout << endl;
    }
}


int main()
{
    ifstream fi(FI);
    fi >> n;

    adj.assign(n, vector<int>());

    int u, v;

    while (fi >> u >> v)
    {
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    greedyColoring(adj);

    return 0;
}