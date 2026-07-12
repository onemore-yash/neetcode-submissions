class Solution {
    int dp(int i,vector<int>&nums,vector<int>&t){
        if(i>=nums.size())return 0;
        if(t[i]!=-1)return t[i];
        int take=nums[i]+dp(i+2,nums,t);
        int nottake=dp(i+1,nums,t);
        return t[i]=max(take,nottake);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>t(nums.size(),-1);
       return dp(0,nums,t);
    }
};
