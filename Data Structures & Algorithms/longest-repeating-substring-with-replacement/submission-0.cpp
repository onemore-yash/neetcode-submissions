class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,maxf=0;
        int ans=0;
        unordered_map<int,int>cnt;

        for(int r=0;r<s.size();r++){
            cnt[s[r]]++;
            maxf=max(maxf,cnt[s[r]]);

            while((r-l+1)-maxf>k){
                cnt[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
