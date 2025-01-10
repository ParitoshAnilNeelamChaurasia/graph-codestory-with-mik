(DFS) -> undirected graph

  // jo call karta hai -> wo parent hota hai 

  ex
2 calls 3  ==>>> 2->3 => therefore 2 is the parent of 3
1 calls 2,4  ==>> therefore 1 is the parent of  2,4 

  // par hum waha pe nahi ja sakte hai jaha se call aaya hai waha se jisne call kiya hai

0 ----------------- 1 ------------------2
                    |                   |
                    |                   |
                    |                   |
                    4 ----------------- 3

  0 -> 1
  1 -> 0,2,4
  2 -> 1,3
  3 -> 2,4
  4 -> 1,3

  // initially mark only 0 -> visited
  0 1 2 3 4
  T F F F F
  initially we can go from 0 -> 1  -> and 1 is not visited

  // now mark 1 visited and check that 0 is the parent of 1 
  / if parent -> happens -> than mark it visited

  // CONDITION FOR PARENT 
  0->1
  
  0 1 2 3 4
  T T F F F


// from 1 -> where u can go  -> 2,4,0
cant go from 1 -> 0 as 0 is the parent  (parent of 1 -> 2)
// now go to 2
  0 1 2 3 4
  T T T F F

// now go to 4

  0 1 2 3 4
  T T T F T

// now go from 4
to 3
  0 1 2 3 4
  T T T T T    (mark 3 true)  -> as 3 is the parent of 4

// from 4 we can go to 1,3

but 3 -> parent hai => // 3 pe nhi ja sakte hai


  // now goes to 1
1 is not the parent of 4 and if we fount true => than cycle is present 


  // in undirected graph there is a problem arises that it marked a single line as cycle 

  as given above

map -> mp

  0 -> 1
  1 -> 0


  means

  for 1 -> parent = 0
  for 0 -> parent = 1

  // we have to check a condition

  that "u" is not the parent of "v"
  // mark it 

  if(v == parent)
  continue ;


/******************************        CODE               ************************************************/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


///////////////////////////////////////////////////////           function start           \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
class Solution {
  public:
    // u -> represents child
    // parent -> represents parent
    bool is_cycle(vector<vector<int>> &adj , int u , vector<int> &vis , int parent)
    {
        // if goes to any node mark it visited
        vis[u] = true ;
        
        for(auto &v : adj[u])
        {
            // jaha pe ja rahe hai wo agar parent ke equal ho gaya to continue 
            if(v == parent)
            {
                continue ;
            }

            // vis[v] => already visited 
            there is a cycle present
            if(vis[v] == true)
            {
                return true ;
            }
            
            if(is_cycle(adj , v , vis , u) == true)
            {
                return true ;
            }
        }
        return false ;
    }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size() ;
        
        vector<int> vis(n,0) ;
        
        for(int i = 0 ; i < n ; ++i)
        {
            // if not visited and we get the cycle -> than return true
            if(!vis[i] && is_cycle(adj , i , vis , -1) )
            {
                return true ;
            }
        }
        return false ;
        
    }
};

////////////////////////////////////////////////////////////////        function end                    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



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
