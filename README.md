The repository includes a version of realization of algorithm 1-4 in the paper `Cyclic vertex connectivity for (4,5,6)-fullerene graphs`.

We suggest you run the codes with C++11, Python3.8 or higher versions. 



## Input Format

For all the codes, we use the uniform format to input a graph below:

The first line with two integers denoting the number of vertexes and edges of the undirected graph, and we limit the index of vertexes in [1,n]

Then input m lines, each line with two integers u,v, denoting an undirected edge (u,v)

See .txt files in folder `testcases` for example. You can also use the files to test the codes.



## Code Introduction

### checker.py

Input a graph, output a bool denoting whether the graph is (4,5,6) fullerene graph.

Note that the code using the `networkX` to calculate, so you should install it before run the code. See [docs](https://networkx.org/documentation/latest/index.html) for details.



### main.cpp

Input a graph, output the results of algorithm 1 and algorithm 2 in the paper.

The only function in this code is `main` function.

This code is the only c++ code with `main` function, so it's the code that you should compile and run. Do not try to run other c++ codes since they have no `main` function.

This code calls all the other c++ codes below.



### inputGraph.cpp

The only function in the code is `input`.

```c++
void input(vector<vector<int>> &e, int &n, int &m)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`.
- `n` is the number of vertexes.
- `m` is the number of edges.

The function asks for input rom `stdin`, you can type the data or using `freopen()` to read data from file. Then the data would be saved in `e`, `n`, `m`.



### loopCheck.cpp

There's two functions  in the code:

```c++
bool isExistLoop(const vector<vector<int>> &e)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`.

return a bool denoting that whether the graph `e` exists a simple cycle of length 4.



```c++
int getG(const vector<vector<int>> &e)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`.

return an integer denoting the girth of the graph `e`.



### algo1.cpp

The only function in the code is the algorithm 1 in the paper:

```c++
int algo1(const vector<vector<int>> &e, int g, int m)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`. It should be guaranteed that `e` is (4,5,6) fullerene graph.
- `g` is the girth of the graph.
- `m` is the number of edges.

return an integer denoting the cyclic vertex connectivity of graph `e`.

It calls the functions `algo3` and `algo4` below.



### algo2.cpp

The only function in the code is the algorithm 2 in the paper:

```c++
int algo2(const vector<vector<int>> &e, int g, int m)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`. It should be guaranteed that `e` is (4,5,6) fullerene graph.
- `g` is the girth of the graph.
- `m` is the number of edges.

return an integer denoting the cyclic edge connectivity of graph `e`.

It calls the function `algo4` below.



### algo3.cpp

The core function in the code is the algorithm 3 in the paper:

```c++
int algo3(const vector<vector<int>> &e)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`. It should be guaranteed that `e` is (4,5,6) fullerene graph and `n` < 16.



Other functions supporting `algo3`:

```c++
int calcHash(const vector<vector<int>> &e, int r)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`. It should be guaranteed that `e` is (4,5,6) fullerene graph and `n` < 16.
- `r` is root vertex's index.

The function convert graph `e` into BFS tree with root vertex `r`, and calculate hash of tree via the hash function: $\sum_{u=1}^n p_1^{d_u}\times p_2^{siz_u}\bmod 998244353$, where $p_1=13331,p_2=10007$ are primes. $d_u$ is the depth of vertex u and $siz_u$ is the number of sons in BFS tree of vertex u.



```c++
void preDeal(string figIndex, set<int> &hashs)
```

- `figIndex` is part of the filename in `testcases`. For example if a file named `fig28a.txt`, then it should be `28a`.
- `hashs` is the set of hash value which are the results of calling this function.

The function use `input` and `freopen` to read a file's data to get a graph, then calculate all the hash of BFS tree using every vertex as root vertex via function `calcHash`.

You needn't call this function. This function is a pre deal function and get the constants `hashs_fig8` and `hashs_fig28a` in advance.



```c++
bool checkIsomorphic(const vector<vector<int>> &e, const set<int> &hashs)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`. It should be guaranteed that `e` is (4,5,6) fullerene graph and `n` < 16.
- `hashs` is the set of all hash values of a specific graph. It can be `hashs_fig8` or `hashs_fig28a`.

The function calculate hash value of `e` with specific root vertex(using vertex 1), and check whether the hash value is included in the hash set. If included, then we could assert `e` is isomorphic with the given graph, and returns true. Otherwise, it returns false.

Since it's judged using hash, then it may misjudge with low possibility.



### algo4.cpp

The only function in the code is the algorithm 4 in the paper:

```c++
int algo4(const vector<vector<int>> &e, int m)
```

- `e` is adjacency table, vertexes indexed from 1 to `n`. It should be guaranteed that `e` is (4,5,6) fullerene graph.
- `m` is the number of edges.

return an bool denoting whether the cyclic vertex connectivity of graph `e` is 3.



## Contact

> The codes' author is ZiXin Qin, whose Github account is [here](https://github.com/lr580). If you find bugs, welcome to contact me at any time or leave an issue.