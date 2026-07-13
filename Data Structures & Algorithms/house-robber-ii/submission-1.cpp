class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size()==1)return nums[0];
        int p1=0,p2=0;
        int res1=0;
        for(int i=1;i<nums.size();i++){
            int t=max(nums[i]+p2,p1);
            p2=p1;
            p1=t;
        }
        res1=p1;
        p1=0,p2=0;
        int res2=0;
        for(int i=0;i<nums.size()-1;i++){
            int t=max(nums[i]+p2,p1);
            p2=p1;
            p1=t;
        }
        res2=p1;

        return max(res1,res2);
    }
};
