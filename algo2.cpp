#ifndef ALG2
#define ALG2
#include <vector>
#include "algo4.cpp"
using namespace std;
// An algorithm determining the cyclic edge connectivity of  (4, 5, 6)-fullerene graphs.
int algo2(const vector<vector<int>> &e, int g, int m)
{
    if (g == 5)
    {
        return 5;
    }
    else
    {
        int ck = algo4(e, m);
        if (ck == 3)
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
}
#endif
