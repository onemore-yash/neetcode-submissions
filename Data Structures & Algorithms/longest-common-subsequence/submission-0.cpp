class Solution {
    int fun(int i,int j,string& text1,string& text2,auto& dp){
        if(i==text1.length() || j==text2.length())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(text1[i]==text2[j])return 1+fun(i+1,j+1,text1,text2,dp);
        return dp[i][j]=max(fun(i+1,j,text1,text2,dp),fun(i,j+1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return fun(0,0,text1,text2,dp);
    }
};
