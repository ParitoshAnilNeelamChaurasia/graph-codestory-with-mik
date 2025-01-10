adjacency matrix takes O(V*V) space complexity whereas adjacency list takes O(V+E) space complexity therfore we prefer adjacency list over adjacency matrix

// CREATION OF ADJACENCY LIST

vertices = {0,1,2,3}

[[1,0],[2,0],[2,1],[3,1]]

// first create unordered map to store the vertices

unordered_map<int,vecotor<int>> adj

  for(vector<int> &vec : pre_vector_given)
  {
      int v = vec[0] ;
      int u = vec[1] ;

      adj[u].push_back(u) ;
      adj[v].push_back(u) ;

  }
