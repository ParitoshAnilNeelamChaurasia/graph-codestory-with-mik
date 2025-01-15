// https://leetcode.com/problems/course-schedule-ii/description/

// in which order u can complete the course if u can complete all the course


  0  ----->>> 1 ----->>> 3
   \                    /|\
     \                   |  
     _\|                 |
         2 --------------

    o/p -> 0,2,1,3


    // BFS
class Solution {
public:
    vector<int> topo_sort(unordered_map<int,vector<int>> &adj , vector<int> &indegree , int numCourses)
    {
        queue<int> q ;
        vector<int> res ;

        int count = 0 ;

        for(int i = 0 ; i < numCourses ; ++i)
        {
            if(indegree[i] == 0)
            {
                res.push_back(i) ;
                count++ ;
                q.push(i) ;
            }
        }

        while(!q.empty())
        {
            int u = q.front() ;
            q.pop() ;

            for(int &v : adj[u])
            {
                indegree[v]-- ;

                if(indegree[v] == 0)
                {
                    res.push_back(v) ;
                    count++ ;
                    q.push(v) ;
                }
            }
        }
        if(count == numCourses)
        return res ;

        return {} ;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size() ;

        unordered_map<int,vector<int>> adj ;

        vector<int> indegree(numCourses , 0) ;

        for(int i = 0 ; i < n ; ++i)
        {
            int a = prerequisites[i][0] ;
            int b = prerequisites[i][1] ;

            adj[b].push_back(a) ;

            indegree[a]++ ;
        }

        return topo_sort(adj , indegree , numCourses) ;
    }
};


// DFS

class Solution {
public:
    vector<int> ans;

    bool f(unordered_map<int, vector<int>> &mp, int u, vector<bool> &visited, vector<bool> &isRecursion) {
        visited[u] = true;
        isRecursion[u] = true;

        for (int &v : mp[u]) 
        {
            if (!visited[v] && f(mp, v, visited, isRecursion)) 
            {
                return true;
            } 
            else if (isRecursion[v]) 
            {
                return true;
            }
        }
        isRecursion[u] = false;
        ans.push_back(u);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < prerequisites.size(); ++i) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            mp[b].push_back(a);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> isRecursion(numCourses, false);

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && f(mp, i, visited, isRecursion)) {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
