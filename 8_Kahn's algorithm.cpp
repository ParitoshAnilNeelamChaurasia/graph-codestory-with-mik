topological sorting using BFS => kahn's algorithm

indegree => no. of incoming nodes
outdegree => no. of outgoing nodes



that nodes came first whose indegree is less and than comes a node with more indegree


                                              -----------------------------------
--------------------------------------------  |                                 |
|                                           |  |                                 |
|                                           \|/                                 |
|                        3 -----------------> 1-------------> 4                 |
|                       /|\                  /|\             /|\                |
|                        |                    |               |                 |
|                       0                    |               |                  |
|                       |                    |               |                  |
|                      \|/                   |               |                  |
--------------------    2 --------------------               5-------------------

adjacency list:
0 -> 3,2
1 -> 4
2 -> 3,1
3 -> 1
4 -> 
5 -> 1,4

first push that elements whose indegree = 0

  queue => {0,5)




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size() ;
        
        vector<int> indegree(n , 0) ;
        
        queue<int> q ;
        
        for(int u = 0 ; u < n ; ++u)
        {
            for(int &v : adj[u])
            {
                indegree[v]++ ;
            }
        }
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(indegree[i] == 0)
            {
                q.push(i) ;
            }
        }
        
        vector<int> res ;
        
        while(!q.empty())
        {
            int curr = q.front() ;
            res.push_back(curr) ;
            q.pop() ;
            
            for(int &v : adj[curr])
            {
                indegree[v]-- ;
                
                if(indegree[v] == 0)
                {
                    q.push(v) ;
                }
            }
        }
        return res ;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends
