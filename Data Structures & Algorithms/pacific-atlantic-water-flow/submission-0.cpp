class Solution {
    void dfs(int r, int c, vector<vector<bool>>&ocean,vector<vector<int>>&heights){
        ocean[r][c]=true;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx=r+dx[i],ny=c+dy[i];
            if(nx>=0 && nx<heights.size() && ny>=0 && ny<heights[0].size() && !ocean[nx][ny] && heights[nx][ny]>=heights[r][c]){
                dfs(nx,ny,ocean,heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<bool>> pac(row,vector<bool>(col,false));
        vector<vector<bool>> atl(row,vector<bool>(col,false));

        for(int c=0;c<col;c++){
            dfs(0,c,pac,heights);
            dfs(row-1,c,atl,heights);
        }
        for(int r=0;r<row;r++){
            dfs(r,0,pac,heights);
            dfs(r,col-1,atl,heights);
        }
        vector<vector<int>>res;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i,j});
            }
        }
        return res;
    }
};
