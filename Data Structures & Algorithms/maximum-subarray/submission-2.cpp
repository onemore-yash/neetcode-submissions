class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0,n=nums.size();
        int res=nums[0];
        int temp=0;
        for(int i=0;i<n;i++){
            if(temp<0 ){
                temp=0;
            }
            temp+=nums[i];
            res=max(temp,res);
        }
        return res;
    }
};
