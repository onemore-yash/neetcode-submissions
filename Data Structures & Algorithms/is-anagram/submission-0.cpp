class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int n=s.length();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            mp[t[i]-'a']--;
            if(mp[t[i]-'a']<0)return false;
        }

        return true;
    }
};
