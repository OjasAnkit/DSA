#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int dfs(vector<bool> visited, vector<int> subtree_sizes, int node, unordered_map<int, vector<int>> tree)
{
    visited[node] = true;
    int size = 1;
    for (int neighbor : tree[node])
    {
        if (!visited[neighbor])
        {
            size += dfs(visited, subtree_sizes, neighbor, tree);
        }
    }
    subtree_sizes[node] = size;
    return size;
}

bool check_equal_children(vector<int> subtree_sizes, int node, unordered_map<int, vector<int>> tree)
{
    unordered_set<int> sizes;
    for (int neighbor : tree[node])
    {
        if (subtree_sizes[neighbor] < subtree_sizes[node])
        {
            sizes.insert(subtree_sizes[neighbor]);
        }
    }
    return sizes.size() <= 1;
}

int countGoodNodes(vector<vector<int>> &edges)
{
    vector<int> subtree_sizes;
    int n = edges.size();
    unordered_map<int, vector<int>> tree;
    vector<bool> visited;

    subtree_sizes.resize(n);
    visited.resize(n, false);

    for (auto &edge : edges)
    {
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }

    dfs(visited, subtree_sizes, 0, tree);

    int answer = 0;
    for (int i = 0; i < n; ++i)
    {
        if (check_equal_children(subtree_sizes, i, tree))
        {
            answer++;
        }
    }

    for(int k:subtree_sizes)
        cout<<k<<endl;

    return answer;
}

int main()
{
    int red = 1;
    int blue = 13;
    // int ans = max(makeRows(red, blue), makeRows(blue, red));
    // cout << ans;
    // vector<int> v = {1, 2, 1, 1, 2, 1, 2};
    // vector<int> v = {1, 5, 9, 4, 2};
    // cout << max(returnMax(v, 0), returnMax(v, 1));
    // cout << returnMax(v, 0);
    int a;
    int m = a * a;
    vector<int> v = {1, 2, 2, 3, 3};

    vector<vector<int>> edges1 = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {0, 5}, {1, 6}, {2, 7}, {3, 8}};

    vector<vector<int>> edges2 = {
        {0, 1}, {1, 2}, {1, 3}, {1, 4}, {0, 5}, {5, 6}, {6, 7}, {7, 8}, {0, 9}, {9, 10}, {9, 12}, {10, 11}};

    // cout << singleNonDuplicate(v);
    cout << countGoodNodes(edges1) << endl;
    cout << countGoodNodes(edges2) << endl;

    return 0;
}
