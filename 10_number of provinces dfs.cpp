// https://leetcode.com/problems/number-of-provinces/description/

// using DFS

class Solution {
public:
    void dfs(int u , vector<bool> &visited , unordered_map<int,vector<int>> &adj)
    {
        visited[u] = true ;

        for(int &v : adj[u])
        {
            if(visited[v] == false)
            {
                dfs(v , visited , adj) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;

        unordered_map<int,vector<int>> adj ;

        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(isConnected[i][j] == 1)
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
                dfs(i , visited , adj) ;
                count++ ;
            }
        }
        return count ;
    }
};
