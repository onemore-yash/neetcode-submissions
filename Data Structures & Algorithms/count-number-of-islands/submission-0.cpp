class Solution {
    void dfs(int i,int j,auto& grid,auto& vis){
        vis[i][j]=1;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int p=0;p<4;p++){
            int nx=i+dx[p],ny=j+dy[p];
            if(nx>=0 && ny>=0 && nx<grid.size() && ny<grid[0].size() && grid[nx][ny]=='1' && !vis[nx][ny]){
                vis[nx][ny]=1;
                dfs(nx,ny,grid,vis);
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
