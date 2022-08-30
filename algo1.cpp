#ifndef ALG1
#define ALG1
#include <vector>
#include <queue>
#include "algo3.cpp"
#include "algo4.cpp"
using namespace std;
// An algorithm determining the cyclic vertex connectivity of  (4, 5, 6)-fullerene graphs.
int algo1(const vector<vector<int>> &e, int g, int m)
{ // using parameter m to avoid calculate m again, same as algo.2
    int n = e.size() - 1;
    if (g == 5)
    {
        return 5;
    }
    else if (g == 4)
    {
        int ck = algo4(e, m);
        if (ck == 3)
        {
            return 3;
        }
        else
        {
            if (n >= 16)
            {
                return 4;
            }
            else
            {
                return algo3(e);
            }
        }
    }
    return g;
}
#endif
