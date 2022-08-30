#(4,5,6) fullerene graph is a planarity graph of 3-regular, 3-edge-connected, with cycles of 4 or 5 or 6 length only.
// dertemining  whether a graph G is a (4,5,6) fullerene graph.
import networkx as nx

g = nx.Graph()
n, m = [int(i) for i in input().strip().split()]
for i in range(m):
    u, v = [int(i) for i in input().strip().split()]
    g.add_edge(u, v)

is3Regular = nx.is_k_regular(g, 3)

is3Connected = nx.is_k_edge_connected(g, 3)

isPlanar = nx.is_planar(g)

#only 4,5,6 cycle -> do not exist basic cycle whose length <=3 or >=7 (basic cycle can form all cycles in the graph via using bitwise xor with edges)
cycles = nx.minimum_cycle_basis(g)
minLen = len(min(cycles, key=lambda x: len(x)))
maxLen = len(max(cycles, key=lambda x: len(x)))
isOnly456 = minLen >= 4 and maxLen <= 6

isFullerene = is3Regular and is3Connected and isPlanar and isOnly456
print(isFullerene)
