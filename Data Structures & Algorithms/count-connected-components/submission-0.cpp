class Solution {
    void bfs(int node,vector<vector<int>>&adj,vector<bool>&vis){
        vis[node]=true;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int t=q.front();
            q.pop();
            vis[t]=true;
            for(auto neigh:adj[t]){
                if(!vis[neigh]) q.push(neigh);
            }
        }
        return;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
