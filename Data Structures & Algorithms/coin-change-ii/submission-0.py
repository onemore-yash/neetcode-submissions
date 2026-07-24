class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        n=len(coins)
        ans=0
        dp=[[-1]*(amount+1) for _ in range(n+1)]
        def fun(i,target):
            if target==0:
                return 1
            if i>=n or target<0:
                return 0
            if dp[i][target]!=-1:
                return dp[i][target]

            take=fun(i,target-coins[i])
            nottake=fun(i+1,target)

            dp[i][target]=take+nottake
            return dp[i][target]
        
        return fun(0,amount)
