#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> subtree_sizes;
    unordered_map<int, vector<int>> tree;

    int dfs(int node, int parent)
    {
        int size = 1; // Start with the node itself
        for (int neighbor : tree[node])
        {
            if (neighbor != parent)
            { // Avoid revisiting the parent node
                size += dfs(neighbor, node);
            }
        }
        subtree_sizes[node] = size;
        return size;
    }

    bool check_good_node(int node)
    {
        unordered_set<int> sizes;
        for (int child : tree[node])
        {
            if (subtree_sizes[child] < subtree_sizes[node])
            {
                sizes.insert(subtree_sizes[child]);
            }
        }
        return sizes.size() <= 1; // True if all sizes are the same or if there are no children
    }

    int countGoodNodes(int n, vector<vector<int>> &edges)
    {
        subtree_sizes.resize(n);

        // Step 1: Build the tree
        for (auto &edge : edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        // Step 2: DFS to calculate subtree sizes
        dfs(0, -1);

        // Step 3: Count good nodes
        int good_nodes_count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (check_good_node(i))
            {
                good_nodes_count++;
            }
        }

        return good_nodes_count;
    }
};

int main()
{
    Solution sol;

    // Example 1
    int n1 = 8;
    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 5}, {1, 6}, {2, 7}, {3, 8}};
    cout << "Number of good nodes: " << sol.countGoodNodes(n1, edges1) << endl;

    // Example 2
    int n2 = 12;
    // Second vector of edges
    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {1, 3}, {1, 4}, {0, 5}, {5, 6}, {6, 7}, {7, 8}, {0, 9}, {9, 10}, {9, 12}, {10, 11}};
    cout << "Number of good nodes: " << sol.countGoodNodes(n2, edges2) << endl;

    return 0;
}
