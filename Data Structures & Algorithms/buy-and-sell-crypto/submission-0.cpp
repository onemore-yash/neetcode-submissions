class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int leftmin=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(leftmin>prices[i])leftmin=prices[i];
            else ans=max(ans,prices[i]-leftmin);
        }
        return ans;
    }
};
