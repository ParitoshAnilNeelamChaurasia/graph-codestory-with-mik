// https://leetcode.com/problems/is-graph-bipartite/description/


class Solution {
public:
    bool bfs(vector<vector<int>> &graph , vector<int> &color , int u , int curr_color)
    {
        queue<int> q ;
        q.push(u) ;

        color[u] = curr_color ;

        while(!q.empty())
        {
            int node = q.front() ;
            q.pop() ;

            for(int &v : graph[node])
            {
                if(color[v] == curr_color)
                {
                    return false ;
                }

                if(color[v] == -1)
                {
                    int curr_color_v = 1 - curr_color ;

                    if(bfs(graph , color , v , curr_color_v) == false)
                    {
                        return false ;
                    }
                }
            }
        }
        return true ;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size() ;

        vector<int> color(n,-1) ;

        for(int i = 0 ; i < n ; ++i)
        {
            if(color[i] == -1)
            {
                if(bfs(graph , color , i , 1) == false) 
                    return false ;
            }
        }
        return true ;
    }
};
