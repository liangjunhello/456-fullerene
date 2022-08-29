#ifndef LOOPCHECK
#define LOOPCHECK
#include <vector>
#include <queue>
using namespace std;
// check if the graph exists 4-cycles
bool isExistLoop(const vector<vector<int>> &e)
{
    int n = e.size() - 1; // number of vertexes
    vector<int> vis(n + 1, 0);
    vector<int> dep(n + 1, 0); // depth of BFS
    // BFS
    for (int i = 1; i <= n; ++i)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(i, 0)); // pair(index of vertex, depth)
        while (!q.empty())
        {
            pair<int, int> pr = q.front();
            q.pop();
            int u = pr.first;
            int d = pr.second;
            if (d > 2)
            {
                break;
            }
            if (vis[u] == i) // if i-th BFS visited this vertex
            {
                if (dep[u] == d) // visit again with the same depth, then meet a loop
                {
                    return true;
                }
                continue;
            }
            vis[u] = i;
            dep[u] = d;
            for (int v : e[u])
            {
                q.push(make_pair(v, d + 1));
            }
        }
    }
    return false;
}
int getG(const vector<vector<int>> &e)
{ // the girth of the graph
    return isExistLoop(e) ? 4 : 5;
}
#endif