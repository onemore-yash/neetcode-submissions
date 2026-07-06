class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(('a'<=s[i] && 'z'>=s[i])|| (s[i]>='0' && s[i]<='9'))temp+=s[i];
            else if('A'<=s[i] && 'Z'>=s[i])temp+=(s[i]+32);
            else continue;
        }

        int i=0,j=temp.length()-1;
        while(i<j)if(temp[i]!=temp[j])return false;
        else {
            i++;j--;
        }
        return true;
    }
};
