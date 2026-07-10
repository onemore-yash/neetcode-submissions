class Solution {
    int n;
    int m;
    
    
    bool dfs(int i,int r,int c,string s,vector<vector<char>>&board){
        if(i==s.length())return true;
        if(r<0 || c<0 || r>=n || c>=m || board[r][c] != s[i] || board[r][c] == '#')return false;

        board[r][c]='#';
        bool ans=dfs(i+1,r+1,c,s,board) || dfs(i+1,r-1,c,s,board) || dfs(i+1,r,c+1,s,board) || dfs(i+1,r,c-1,s,board);
        board[r][c]=s[i];
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(0,i,j,word,board))
                    return true;
            }
        }
        return false;
    }
};
