// can paint graph with 2 different color such that no adjacent node color must not be same

       Red color
       1
     /   \
    2-----3 - 4  => odd length cycle => can never be bipartite => red colors are adjacent
blue     red 


class Solution {
public:
    bool bfs(int u, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(u);
        color[u] = 0;  // Start coloring node `u` with color 0

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int &neighbor : graph[node]) {
                // Adjacent nodes can't have the same color
                if (color[neighbor] == color[node]) {
                    return false;
                }
                // Color the uncolored neighbor with the opposite color
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node];
                    q.push(neighbor);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // Initialize all nodes with no color (-1)

        for (int i = 0; i < n; ++i) {
            // If node `i` is not colored, start a BFS from it
            if (color[i] == -1) {
                if (!bfs(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
