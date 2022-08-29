#include <iostream>
#include <vector>
#include "inputGraph.cpp"
#include "loopCheck.cpp"
#include "algo1.cpp"
#include "algo2.cpp"
using namespace std;

signed main()
{
    vector<vector<int>> e; // adjacency table
    int n, m;              // number of vertexes, number of edges
    input(e, n, m);
    int g = getG(e);
    cout << algo1(e, g, m) << '\n';
    cout << algo2(e, g, m) << '\n';
    return 0;
}