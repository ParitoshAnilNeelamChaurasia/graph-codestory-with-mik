

BFS is always used to find the shortest path in a graph


// EXAMPLE

visiting from 0 to 3  -> IN DFS it takes to go to the DFS(0) -> DFS(1) -> DFS(2) -> DFS(3)
                      -> IN BFS it takes only 2 levels to reach to 3
                        level 1  0 -> {1.2)
                        level 2  0 -> {3}
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

// In BFS -> level is calculated using the number of adjacent nodes 

means

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    
    void BFS(unordered_map<int,vector<int>> adj , int u , vector<bool> &visited , vector<int> &res)
    {
        queue<int> q ;
        q.push(u) ;
        visited[u] = true ;
        
        res.push_back(u) ;
        
        while(!q.empty())
        {
            int u = q.front() ;
            q.pop() ;
            
            for(int & v : adj[u])
            {
                if(!visited[v])
                {
                    q.push(v) ;
                    visited[v] = true ;
                    res.push_back(v) ;
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> mp[]) {
        unordered_map<int,vector<int>> adj ;
        
        for(int i = 0 ; i < V ; ++i)
        {
            for(auto it = mp[i].begin() ; it != mp[i].end() ; ++it)
            {
                adj[i].push_back(*it) ; 
            }
        }
        
        vector<bool> visited(V,false) ;
        vector<int> res ;
        
        BFS(adj , 0 , visited , res) ;
        
        return res ;
    }
};

level 0 -> 0
level 1 -> 1.2  (can visit from 0)
level 2 -> 3,9  (can visit from 0 in 2 steps)

// make a queue and push in queue and than visit the neighbouring nodes for each traversal -> and as a result a queue is maintained to gave BFS
