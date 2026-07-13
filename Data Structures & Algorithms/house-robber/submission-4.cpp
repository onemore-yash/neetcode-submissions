class Solution {    
public:
    int rob(vector<int>& nums) {
        int p2=0;
        int p1=0;

        for(int i=0;i<nums.size();i++){
            int cur=max(p1,nums[i]+p2);
            p2=p1;
            p1=cur;
        }
       return p1;
    }
};
