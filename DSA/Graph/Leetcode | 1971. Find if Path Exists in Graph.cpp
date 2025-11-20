//https://leetcode.com/problems/find-if-path-exists-in-graph/?envType=problem-list-v2&envId=graph
class Solution {
public:

    bool dfs(vector<vector<int>> & adj, vector<bool> &visited, int node, int destination){
        if(node==destination){
            return true;
        }
        visited[node]=1;
        for(auto &child : adj[node]){
            if(!visited[child]){
                if(dfs(adj, visited, child, destination))
                    return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n,0);

        for(auto& x : edges){
            int u=x[0], v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }
        return dfs(adj, visited, source, destination);
    }
};
