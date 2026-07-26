class Solution:
    def jump(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[-1]*(n+1)
        def dfs(i):
            if i==n-1:
                return 0
            if nums[i]==0:
                return float('inf')
            if dp[i]!=-1:
                return dp[i]
            end=min(n-1,i+nums[i])
            res=float('inf')
            for j in range(i+1,end+1):
                res=min(res,1+dfs(j))
            dp[i]=res
            return res

        return dfs(0)

