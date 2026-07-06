class Solution {
public:

    string encode(vector<string>& strs) {
       string res;
        for (const string& s : strs) {
            res.append(to_string(s.size()));
            res.push_back('#');
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int i=0;
        string t="";
        while(i<s.size()){
            int j=i;

            while(s[j]!='#')j++;
            int len=stoi(s.substr(i,j-i));
            i=j+1;
            j=i+len;
            ans.push_back(s.substr(i,len));
            i=j;
        }
        return ans;
    }
};
