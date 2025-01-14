class Solution {
public:
    void bfs(unordered_map<int , vector<int>> &adj , int u , vector<bool> &visited)
    {
        queue<int> q ;
        q.push(u) ;
        visited[u] = true ;

        while(!q.empty())
        {
            int curr = q.front() ;
            q.pop() ;

            for(int &v : adj[curr])
            {
                if(!visited[v] )
                {
                    q.push(v) ;
                    bfs(adj , v , visited) ;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;

        unordered_map<int , vector<int>> adj ;

        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(isConnected[i][j] == 1 )
                {
                adj[i].push_back(j) ;
                adj[j].push_back(i) ;
                }
            }
        }

        int count = 0 ;

        vector<bool> visited(n , false) ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(!visited[i])
            {
                bfs(adj , i , visited) ;
                count++ ;
            }
        }
        return count ;
    }
};
