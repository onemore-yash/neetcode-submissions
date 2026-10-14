class Solution {
    bool backtrack(string s,int i,int sum,vector<vector<int>>&dp){
        if(sum<0)return false;
        if(i==s.length()){
            return sum==0;
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(s[i]=='(')return dp[i][sum]=backtrack(s,i+1,sum+1,dp);
        if(s[i]==')')return dp[i][sum]=backtrack(s,i+1,sum-1,dp);
        return dp[i][sum]=backtrack(s,i+1,sum,dp)||backtrack(s,i+1,sum+1,dp)||backtrack(s,i+1,sum-1,dp);

    }
public:
    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return backtrack(s,0,0,dp);
    }
};
