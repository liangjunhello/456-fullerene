#ifndef INPUTGRAPH
#define INPUTGRAPH
#include <vector>
#include <iostream>
#include "loopCheck.cpp"
using namespace std;
/* Input format:
The first line with two integers denoting the number of vertexes and edges of the undirected graph, and we limit the index of vertexes in [1,n]
Then input m lines, each line with two integers u,v, denoting an undirected edge (u,v)
You should guarantee that the input is a (4,5,6) fullerene graph

See folder "testcases" for example.
*/
void input(vector<vector<int>> &e, int &n, int &m)
{
    cin >> n >> m;
    e.clear();
    e.resize(n + 1, vector<int>());
    for (int i = 1; i <= n; ++i)
    {
        e[i].clear();
    }
    for (int i = 1, u, v; i <= m; ++i)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
}
#endif