class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_set<string> st(wordDict.begin(), wordDict.end());

        int n = s.size();
        int maxLen = 0;

        for (auto &word : wordDict)
            maxLen = max(maxLen, (int)word.size());

        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            string cur = "";
            for (int j = i; j < min(n, i + maxLen); j++) {
                cur += s[j];

                if (st.count(cur) && dp[j + 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
