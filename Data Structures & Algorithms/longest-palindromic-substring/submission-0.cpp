class Solution {
public:
    string longestPalindrome(string s) {
        int res=-1;
        int resLen=0;
        for(int i=0;i<s.length();i++){
            int l=i,r=i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>resLen){
                    resLen=r-l+1;
                    res=l;
                }
                l--;
                r++;
            }
                l=i,r=i+1;
                while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>resLen){
                    resLen=r-l+1;
                    res=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(res,resLen);
    }
};
