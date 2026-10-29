class Solution {
    vector<vector<int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>>dp;

    int dfs(vector<vector<int>>&matrix,int r,int c,int prevval){
        int rows=matrix.size(),cols=matrix[0].size();
        if(r<0 || r>=rows || c<0 || c>=cols || matrix[r][c] <= prevval)return 0;

        if(dp[r][c] != -1)return dp[r][c];

        int res=1;
        for (vector<int>d : directions) res=max(res,1+dfs(matrix,r+d[0],c+d[1],matrix[r][c]));

        dp[r][c]=res;
        return res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        dp=vector<vector<int>>(r,vector<int>(c,-1));
        int maxi=0;
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                maxi=max(maxi,dfs(matrix,x,y,INT_MIN));
            }
        }
        return maxi;
    }
};
