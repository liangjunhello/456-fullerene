#ifndef ALG2
#define ALG2
#include <vector>
#include "algo4.cpp"
using namespace std;
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