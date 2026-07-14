class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>dp(nums.size(),false);
        int n=nums.size();
        dp[nums.size()-1]=true;
        for(int i=n-2;i>=0;i--){
            bool f=false;
            for(int j=1;j<=nums[i] && j<n;j++){
            if(dp[i+j]) {
                dp[i]=true;
                f=true;
            }
        }
        if(!f)dp[i]=false;
        }
        return dp[0];
    }
};
