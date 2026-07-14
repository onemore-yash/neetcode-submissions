class Solution {
    int fun(int i,vector<int>&nums,int prev,vector<vector<int>>&dp){
        if(i==nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        int nottake=fun(i+1,nums,prev,dp);
        int take=INT_MIN;
        if(prev==-1 || nums[i]>nums[prev]) take=1+fun(i+1,nums,i,dp);

        return dp[i][prev+1]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(0,nums,-1,dp);
    }
};
