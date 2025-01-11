// detected cycle in directed graph  => adobe , amazon , microsft


               0 ---------- ----> 1
              /|\                |
                  \              |
                    \            |
                      \          |
                        \        |
                          \      |
                            \    |
                                \/
                                2
                 undirected graph logic didn't works  

                 0 -> 1 <- 2          // this logoc fails as 


                 1's parent is 0 
                 but it was shown that its parent is 2  => hence didn't detect cycle

// for correcting this we have to call the in_recursion function every time we get an unvisited node

in_recursion function checks -> that the current node is included in the current dfs call or not


Graph 

          0 -------------->>>> 1 <<<<------------ 2
                  DRY RUN
0 -> 1
1 -> 
2 -> 1


visited vector                                                 in_recursion vector

0   1   2                                                        0   1    1
F   F   F                                                        F   F    F

                    // Making 0 visited
0   1   2                                                        0   1    1
T   F   F                                                        T   F    F

                    // Making 1 visited as its called by 0 => 0  is parent
0   1   2                                                        0   1    1
T   T   F                                                        T   T    F

                    // From 1 -> can't go anywhere => rollback the recursion of 1 => than 0   in in_recursion
0   1   2                                                        0   1    1
T   T   F                                                        T   F    F
                    //  rolling back recursion for => '0'
0   1   2                                                        0   1    1
T   T   F                                                        F   F    F

                   //  running a loop in visited vector => and if the ith elemeent is not visited => than make a dfs call from that element ('2')
0   1   2                                                        0   1    1
T   T   T                                                        F   F    T
                   //  from 2 -> can go to 1 => but 1 is visited  => check '1' is in current recursion stack (in_recursion) => if not => hence cycle no present


//////////////////////////////////////////////////   CODE   \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool is_cycle(vector<vector<int>> &adj , int u , vector<bool> &visited , vector<bool> &in_recursion)
    {
        visited[u] = true ;
        in_recursion[u] = true ;
        
        for(int &v : adj[u])
        {
            // if node not visite
            if(visited[v] == false && is_cycle(adj , v , visited , in_recursion))
            {
                return true ;
            }
            
            else if( visited[v] == true && in_recursion[v] )
            {
                return true ;
            }
        }
        in_recursion[u] = false ;  // backtrack the recursion call
        return false ;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        vector<bool> visited(V, false) ;
        vector<bool> in_recursion(V , false) ;
        
        for(int i = 0 ; i < V ; ++i)
        {
            if(!visited[i] && is_cycle(adj , i , visited , in_recursion)== true)
            {
                return true ;
            }
        }
        return false ;
     }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends
