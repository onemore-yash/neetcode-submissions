class Solution {
    void dfs(int i,vector<int>temp,int sum,vector<int>&nums,int target,vector<vector<int>>& ans){
        if(sum==target){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<nums.size();j++){
            if(sum + nums[j]>target) return;

            temp.push_back(nums[j]);
            dfs(j,temp,sum+nums[j],nums,target,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        dfs(0,{},0,nums,target,ans);
        return ans;
    }
};
