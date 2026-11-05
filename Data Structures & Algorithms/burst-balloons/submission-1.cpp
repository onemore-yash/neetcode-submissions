
class Solution {
public:
    vector<vector<int>> dp;

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        dp.assign(n, vector<int>(n, -1));

        return dfs(nums, 0, n - 1);
    }

    int dfs(vector<int>& nums, int i, int j) {

        if (j - i == 1) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = 0;

        for (int k = i + 1; k < j; k++) {

            int coins = nums[i] * nums[k] * nums[j];

            coins += dfs(nums, i, k);
            coins += dfs(nums, k, j);

            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }
};
