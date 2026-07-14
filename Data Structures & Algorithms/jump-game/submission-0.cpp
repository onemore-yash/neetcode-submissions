class Solution {
    bool fun(int i,vector<int>&nums){
        if(i==nums.size()-1)return true;
        if(i>=nums.size())return false;
        for(int j=1;j<=nums[i];j++){
            if(fun(i+j,nums))return true;
        }
        return false;
    }
public:
    bool canJump(vector<int>& nums) {
        return fun(0,nums);
    }
};
