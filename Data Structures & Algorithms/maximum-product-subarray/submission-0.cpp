class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curMin=1,curMax=1;
        for(auto num:nums){
            int temp=num*curMax;
            curMax=max(max(temp,num*curMin),num);
            curMin=min(min(temp,num*curMin),num);
            res=max(res,curMax);
        }
        return res;
    }
};
