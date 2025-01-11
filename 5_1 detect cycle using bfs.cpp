

  // (node , parent) => write in this form

// make a queue in which we store (node , parent)

if going to an element and element is visited => if element is parent than we can do nothing => else if its not the parent than the cycle is present

0 -> 1,2
1 -> 0
2 -> 0

  // hum node se jaha jaha ja sakte hai usko visited mark kar de

  mark it visited in queue => and pop that element
 (0,-1)             (1,0)
    0 -------------> 1 
    |
    |
    2
   (2,0)


  //////////////////////////////////////////////////        CODE      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool is_cycle(vector<vector<int>> adj , vector<bool> &visited , int u )
    {
        queue<pair<int,int>> q ;
        q.push({u , -1}) ;
        visited[u] = true ;
        
        while(!q.empty())
        {
            pair<int,int> p = q.front() ;
            q.pop() ;
            
            int src = p.first ;
            int parent = p.second ;
            
            for(int &v : adj[src])
            {
                if(!visited[v])
                {
                    visited[v] = true ;
                    q.push({ v , src}) ;
                }
                else if(v != parent)
                {
                    return true ;
                }
            }
        }
        return false ;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size() ;
        
        vector<bool> visited(n , false) ;
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(!visited[i] && is_cycle(adj , visited , i ))
            {
                return true ;
            }
        }
        return false ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends














