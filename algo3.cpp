#ifndef ALG3
#define ALG3
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include "inputGraph.cpp"
using namespace std;

// checkIsomorphic begin
/* a quick way to check isomorphic: hash on tree
 * let r be the root vertex, convert the graph into BFS tree and calculate hash
 * let depth of vertex u is d[u], number of sons of u is siz[u]
 * let prime p1=13331, p2=10007
 * hash function: sum of p1^d[u] * p2^siz[u] mod 998244353, 1<=u<=n
 */
int calcHash(const vector<vector<int>> &e, int r)
{
    const int mod = 1e9 + 7;
    int n = e.size() - 1;
    vector<int> p1(n + 1, 0), p2(n + 1, 0);
    p1[0] = 1, p2[0] = 1;
    p1[1] = 13331, p2[1] = 10007;
    for (int i = 2; i <= n; ++i)
    {
        p1[i] = 1LL * p1[i - 1] * p1[1] % mod;
        p2[i] = 1LL * p2[i - 1] * p2[1] % mod;
    }

    int ans = 0;
    vector<bool> vis(n + 1, false);
    queue<pair<int, int>> q;
    q.push({r, 0});
    while (!q.empty())
    {
        pair<int, int> pr = q.front();
        q.pop();
        int u = pr.first, d = pr.second, siz = 0;
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int v : e[u])
        {
            if (!vis[v])
            {
                ++siz;
                q.push({v, d + 1});
            }
        }
        ans = (1LL * ans + 1LL * p1[d] * p2[siz] % mod) % mod;
    }
    return ans;
}
void preDeal(string figIndex, set<int> &hashs) // do not need to run, it's pre-runned and got the hash sets of two figs
{
    string path = "testcases/fig" + figIndex + ".txt";
    freopen(path.c_str(), "r", stdin);
    vector<vector<int>> e;
    int n, m;
    input(e, n, m);

    for (int i = 1; i <= n; ++i)
    {
        int h = calcHash(e, i);
        hashs.insert(h);
    }

    // below debug: print all hashs
    cout << figIndex << '\n';
    for (int i : hashs)
    {
        printf("%d, ", i);
    }
    printf("\n");
}
/* get hashs_fig8 and hashs_fig28a via the function preDeal() above:
preDeal("8", hashs_fig8);
preDeal("28a", hashs_fig28a);
*/
set<int> hashs_fig8 = {388030401};
set<int> hashs_fig28a = {200234676, 474572549, 649664256, 705375614};

bool checkIsomorphic(const vector<vector<int>> &e, const set<int> &hashs)
{
    int h = calcHash(e, 1);
    if (hashs.find(h) != hashs.end())
    {
        return true;
    }
    return false;
}
// checkIsomorphic end

//  An algorithm determining the cyclic vertex connectivity of a (4, 5, 6)-fullerene graph G with v(G)<16.
int algo3(const vector<vector<int>> &e)
{
    const int infty = 1e9;
    int n = e.size() - 1;
    if (n == 8)
    {
        return infty;
    }
    if (n == 10)
    {
        return infty;
    }
    if (n == 12)
    {
        if (checkIsomorphic(e, hashs_fig8))
        {
            return 4;
        }
        return infty;
    }
    if (n == 14)
    {
        if (checkIsomorphic(e, hashs_fig28a))
        {
            return infty;
        }
        return 4;
    }
    return 0; // impossible branch
}
#endif
