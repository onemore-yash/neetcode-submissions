class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;
        vector<vector<int>>adj(n);
        for(int k=0;k<edges.size();k++){
            adj[edges[k][0]].push_back(edges[k][1]);
            adj[edges[k][1]].push_back(edges[k][0]);
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto neigh:adj[node]){
                if(!vis[neigh]){
                    vis[neigh]=true;
                    q.push(neigh);
                }
            }
        }
        return cnt==n;
    }
};
