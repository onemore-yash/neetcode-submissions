class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>prev(amount+1,0);
        vector<int>cur(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)prev[i]=i/coins[0];
            else prev[i]=1e9;
        }

        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                int nottake=prev[target];
                int take=1e9;
                if(target>=coins[i])take=1+cur[target-coins[i]];
                cur[target]=min(nottake,take);
            }
            prev=cur;
        }
        return (prev[amount]>=1e9)?-1:prev[amount];
    }
};
