// https://leetcode.com/problems/course-schedule/

// DFS Approach
class Solution {
public:
    bool is_cycle(int v, vector<bool>& visited, vector<vector<int>>& adj, vector<bool>& in_recursion) {
        visited[v] = true;
        in_recursion[v] = true;

        for (int &neighbor : adj[v]) {
            // Detect cycle if neighbor is unvisited and causes a cycle, or if it's in the current recursion stack
            if (!visited[neighbor] && is_cycle(neighbor, visited, adj, in_recursion)) {
                return true;
            }
            else if (visited[neighbor] == true && in_recursion[neighbor]) {
                return true;
            }
        }

        in_recursion[v] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> adj(numCourses);
        for (const auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> in_recursion(numCourses, false);

        // Check for cycles in each component of the graph
        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i] && is_cycle(i, visited, adj, in_recursion)) {
                return false;
            }
        }

        return true;
    }
};

// BFS Approach

class Solution {
public:
    bool bfs(unordered_map<int,vector<int>> &adj , int numCourses , vector<int> &indegree)
    {
        queue<int> q ;
        int count = 0 ;

        for(int i = 0 ; i < numCourses ; ++i)
        {
            if(indegree[i] == 0)
            {
                q.push(i) ;
                count++ ;
            }
        }

        while(!q.empty())
        {
            int curr = q.front() ;
            q.pop() ;

            for(int &v : adj[curr])
            {
                indegree[v]-- ;

                if(indegree[v] == 0)
                {
                    count++ ;
                    q.push(v) ;
                }
            }
        }
        return count == numCourses ;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size() ;

        vector<int> indegree(numCourses , 0) ;

        unordered_map<int,vector<int>> adj ;

        for(int i = 0 ; i < n ; ++i)
        {
            int a = prerequisites[i][0] ;
            int b = prerequisites[i][1] ;

            adj[b].push_back(a) ;

            indegree[a]++ ;
        }
        return bfs(adj , numCourses , indegree) ;
    }
};
