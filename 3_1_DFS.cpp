// In tree we don't have the problem of revisiting a node
   once again
   OR  forming a cycle 
// but in graph there is a problem
   that cycle can be formed
               9
               ^
               |
  1  -------> 2 ------> 3
  ^            ^
  |            |
  0 ----------

     // U    V
     0 -> {1,2}
     1 -> {2}
     2 -> {3,9}
     

// create a dfs vector of bool type
     dfs(adj,0,vector)

     void dfs(adj , int u , vector<int> visited)

// if the root is already visited -> return 
if(adj[u] == true)
return ;

// than visit that node
else 
visited[u] = true 

// HOW CAN WE 
U SE KAHA KAHA JA SAKTE HAI


for(int &v : adj[u])
{
  // if not visited than visit that node
  if(!visited[v] )
{
dfs(adj,v,visited)
}
}








// dfs

class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void DFS(unordered_map<int, vector<int>> &mp, int u, vector<bool> &visited, vector<int> &res) {
    if (visited[u] == true) {
        return;
    }

    visited[u] = true;
    res.push_back(u);

    for (int &v : mp[u]) {
        if (!visited[v]) {
            DFS(mp, v, visited, res);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    unordered_map<int, vector<int>> mp;

    // Populate the adjacency map
    for (int u = 0; u < V; ++u) {
        for (auto v = adj[u].begin(); v != adj[u].end(); v++) {
            mp[u].push_back(*v);
        }
    }

    vector<int> res;
    vector<bool> visited(V, false);

    // Assuming the graph is connected, we start DFS from node 0
    DFS(mp, 0, visited, res);

    return res;
}

};
