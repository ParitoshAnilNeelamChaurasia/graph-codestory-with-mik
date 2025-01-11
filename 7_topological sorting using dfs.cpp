

// short

first push children in stack than push me in stack

// if the arrow goes from u to v
than first u came than v came


-> always happens in directed graph  which is acyclic   (DAG)
-> can write multiple topological sorting

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


// topological sorting of above graphs can have more than 1 topological sorting

0 -> 3,2
1 -> 4
2 -> 3,1
3 -> 1
4 -> 
5 -> 1,4


ex  -> 0 2 3 5 1 4
ex2 -> 5 0 2 3 1 4

// checking that the topological sorting is correct or not

take any edge => if "u" came before "v"  => u -> v  => than its correct
              => if "v" came before "u"  => thant its not correct topological sorting

ex 

      1 -> 2 
          \|/  
           3

  topological sorting -> 1 -> 2 -> 3

  not a topological sorting => 2 -> 1 -> 3 (order not followed)

// ///////////////////////////////     \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    how to traverse
    for(int &v : adj[u])
{
if (!vis[v])  DFS(V)
  }


store information in stack  => at last a element left form where we cant go anywhere


when the above for loop overs => than we push (u)



/////////////////////////////////////      DRY          ||||||||||||||||||         RUN             \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


0 -> 3,2
1 -> 4
2 -> 1
3 -> 1,3
4 -> 
5 -> 1,4

    0 1 2 3 4 5
    F F F F F F

                            DFS(0)
    0 1 2 3 4 5               |
    T F F F F F              \|/

                            DFS(3)
    0 1 2 3 4 5               |
    T F F T F F              \|/

    0 1 2 3 4 5              DFS(1)
    T T F T F F                |
                              \|/
    0 1 2 3 4 5               DFS(4)
    T T F T T F

// now we can't go anywhere from 4 -> backtrack
backtrack and push them in stack -> until we didn't get any element which is not visited

   0 1 2 3 4 5                 st -> 4
   T T F T F F

    DFS(1) backtrack
  
   0 1 2 3 4 5                 st -> 4,1
   T T F T F F

   0 1 2 3 4 5                 st -> 4,1,3
   T F F F F F


// DFS(0)  => have unvisited node => mark it visited and go further
   0 1 2 3 4 5                 DFS(0)
   T F F F F F                  |
                               \|/  
  0 1 2 3 4 5                  DFS(2)   -> from 2 -> can go to 1,3  -> both are visited -> hence backtack and push in stack
  T F T F F F                    


push 2 in stack -> st => 4,1,3,2,0

  // from 5 can't go anywhere hence push in stach
  
push 5 in stach -> st => 4,1,3,2,0,5

                        |
                       \|/
                    pop from stach

in the order they came push in vector 

we get our ans
as => 5,0,2,3,1,4



//////////////////////////////////////////////////////      CODE        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

  //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    
    bool dfs(int u , vector<vector<int>> &adj , vector<bool> &visited , stack<int> &st)
    {
        visited[u] = true ;
        
        // first put childs of u inside stack
        for(int &v : adj[u])
        {
            if(!visited[v])
            {
                dfs(v , adj , visited , st) ;
            }
        }
        
        // at the end push u in stack
        st.push(u) ;
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        int n = adj.size() ;
        
        vector<bool> visited(n , false) ;
        stack<int> st ;
        
        for(int i = 0 ; i < n ; ++i)
        {
            if(!visited[i])
            {
                dfs(i , adj , visited , st) ;
            }
        }
        
        vector<int> res ;
        
        while(!st.empty())
        {
            res.push_back(st.top()) ;
            st.pop() ;
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













  
