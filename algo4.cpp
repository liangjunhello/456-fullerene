#ifndef ALG4
#define ALG4
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct node
{
    int i, d; // index of vertex is i,the depth of BFS is d
    node() {}
    node(int a, int b) : i(a), d(b) {}
};
int algo4(const vector<vector<int>> &e, int m)
{
    int n = e.size() - 1;
    vector<int> vis(n + 1, 0);   // whether visited vertex in the i-th BFS
    for (int i = 1; i <= n; ++i) // the i-th BFS's starting vertex is i
    {
        queue<node> q; // BFS queue
        q.push(node(i, 0));
        set<int> cuts; // find vertexex A,B,C in fig.6
        while (!q.empty())
        {
            node nod = q.front();
            q.pop();
            int u = nod.i, d = nod.d;
            if (d > 3) // it can guarantee each BFS with at most O(3*3^3)
            {
                break;
            }
            if (vis[u] == i) // the i-th BFS has visited vertex u
            {
                continue;
            }
            vis[u] = i;
            if (d == 3) // u is possibly ABC
            {
                cuts.insert(u);
            }
            for (int v : e[u])
            {
                q.push(node(v, d + 1));
            }
        }

        if (cuts.size() == 3) // has and only has A,B,C three vertexes(Fig.6)
        {
            if (m - 18 > n - 10)
            {
                return 3;
            }
            return 0;
        }
    }
    return 0;
}
#endif