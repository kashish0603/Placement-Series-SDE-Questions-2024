#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        }
        return false;
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int kruskal(int n, const vector<tuple<int, int, int>>& edges) {
    UnionFind uf(n);
    int mst_weight = 0;
    for (const auto& edge : edges) {
        int weight = std::get<0>(edge);
        int u = std::get<1>(edge);
        int v = std::get<2>(edge);
        if (uf.unite(u, v)) {
            mst_weight += weight;
        }
    }
    return mst_weight;
}

int main() {
    int g_nodes = 4;
    int g_edges = 4;

    vector<int> g_start = {0, 1, 2, 1};
    vector<int> g_end = {1, 2, 3, 3};
    vector<int> g_weights = {10, 6, 5, 15};

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < g_edges; ++i) {
        edges.push_back({g_weights[i], g_start[i], g_end[i]});
    }

    int original_mst_weight = kruskal(g_nodes, edges);

    int min_mst_weight = INT_MAX;
    for (int i = 0; i < g_edges; ++i) {
        vector<tuple<int, int, int>> edges_without_current;
        for (int j = 0; j < g_edges; ++j) {
            if (i != j) {
                edges_without_current.push_back(edges[j]);
            }
        }
        int current_mst_weight = kruskal(g_nodes, edges_without_current);
        min_mst_weight = min(min_mst_weight, current_mst_weight);
    }

    cout << "Minimum sum of MST after removing one edge: " << min_mst_weight << endl;

    return 0;
}
