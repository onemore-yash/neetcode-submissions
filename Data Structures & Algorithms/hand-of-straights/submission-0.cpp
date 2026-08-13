class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if (hand.size() % k != 0) return false;
        unordered_map<int,int>mp;
        int n=hand.size();
        for(int i=0;i<n;i++)mp[hand[i]]++;
        sort(hand.begin(),hand.end());
        for(int num:hand){
            if(mp[num]>0){
                for(int i=num;i<num+k;i++){
                    if(mp[i]==0)return false;
                    mp[i]--;
                }
            }
        }
        return true;
    }
};
