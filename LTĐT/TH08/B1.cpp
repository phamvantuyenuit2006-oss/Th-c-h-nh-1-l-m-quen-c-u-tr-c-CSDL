#include<iostream>
#include<algorithm>
#include<fstream>

using namespace std;

#define FI "test.inp"

vector<vector<int>>adj;

int n,m;

bool isSafe(int v, vector<int>&color, int c)
{
    for (int u:adj[v])
    {
        if (color[u]==c)
        {
            return false;
        }
    }
    return true;
}

bool graphColoring(int m, vector<int> &color, int v)
{
    if (v ==n)
    return true;
    for (int c = 1; c <= m; c++) {

        if (isSafe(v,color,c))
        {
            color[v]=c;
            if (graphColoring(m,color,v+1))
            return true;
            color[v]=0;
        }
    }
    return false;
}

int main()
{
    ifstream fi (FI);
    fi >> n;
    adj.assign(n,vector<int>());
    int u,v;

    while (fi>>u>>v)
    {
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    vector<int>color(n,0);
    int minColor=1;

    while(true)
    {
        fill(color.begin(),color.end(),0);
        if(graphColoring(minColor, color, 0))
        {
            break;
        }
        minColor++;
    }
    cout<<minColor<<"\n";

    for(int c=1;c<=minColor;c++)
    {
        for (int i=0;i<n;i++)
        {
            if (color[i]==c)
            {
                cout<<i+1<<" ";
            }
           
        }
         cout <<"\n";
    }
return 0;

}

