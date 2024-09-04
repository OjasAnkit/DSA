#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Graph {

    public:
    unordered_map<int, vector<int>> adj; //int will store node, vector will store edges

    void addEdge(int u, int v, int directionFlag) {
        /* 
        Here direction flag is used to determine if the 
        graph is an undirected graph, or a directed graph.
        0 -> Undirected Graph will be created
        1 -> Directed Graph will be created
        */
        adj[u].push_back(v);
        if(!directionFlag) {
            adj[v].push_back(u);    
        }
    }

    void printAdjList() {
        for (auto i:adj) {
            /* 
            i.first -> this will return the node
            i.second -> this will give us the edges
            */
            cout<<i.first<<" -> ";
            for(auto j:i.second) {
                cout << j << ", ";
           }
           cout << endl;
        }
    }
};

/* Tasks:
2. dfs
5. connected components
6. topological sort
7. detect cycle in directed graph
8. course schedule
*/

void bfs(Graph g, int source) {
    unordered_map<int, vector<int>> graph = g.adj;
    int n = graph.size();
    vector<bool> vis(n, false);
    queue<int> q;

    q.push(source);

    while (!q.empty()) {
        int top = q.front();
        vis[top] = true;
        cout<<top<<" ";
        q.pop();

        vector<int> edges = graph[top];

        for (auto i:edges) {
            if(!vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }

    return;
}

void dfs(Graph g, int source) {

}

int rottingOranges(vector<vector<int>>& grid) {
    int r = grid.size();
    int c = grid[0].size();
    int minutes = 0;
    queue<vector<int>> q;

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) {
            if(grid[i][j] == 2) {
                q.push({i, j});
            }
        }

    while(!q.empty()) {
        int rottenOranges = q.size();

        for (int i = 0; i < rottenOranges; i++) {
            vector<int> top = q.front();
            int x = top[0];
            int y = top[1];
            // checking for all 4 directions to find fresh orange
            if((x + 1 < r) && (grid[x + 1][y] == 1)) {
                grid[x + 1][y] = 2;
                q.push({x + 1, y});
            }
            if((y + 1 < c) && (grid[x][y + 1] == 1)) {
                grid[x][y + 1] = 2;
                q.push({x, y + 1});
            }
            if((x - 1 >= 0) && (grid[x - 1][y] == 1)) {
                grid[x - 1][y] = 2;
                q.push({x - 1, y});
            }
            if((y - 1 >= 0) && (grid[x][y - 1] == 1)) {
                grid[x][y - 1] = 2;
                q.push({x, y - 1});
            }

            q.pop();
        }

        if(!q.empty()) //if q is empty after above operation -> no oranges were rotten
            minutes ++;
    }

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++) {
            if(grid[i][j] == 1)
                return -1;
        }

    return minutes;
}

void dfs(Graph g, int source) {
    
}
// bool connectedComponents

int main() {
    Graph g;
    int n, m;
    // cout << "Enter the number of nodes: " << endl;
    cin >> n;
    // cout << "Enter the number of edges: " << endl;
    cin >> m;

    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    // g.printAdjList();
    // cout << "BFS Traversal: "; bfs(g, 1);
    
    vector<vector<int>> grid = {{1}};

    cout<<rottingOranges(grid);

    return 0;
}
