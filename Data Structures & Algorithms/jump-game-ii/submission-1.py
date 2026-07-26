class Solution:
    def jump(self, nums: List[int]) -> int:
        n=len(nums)
        dp=[float('inf')]*(n)
        dp[n-1]=0
        for i in range(n-2,-1,-1):
            end=min(n-1,i+nums[i])
            res=float('inf')
            for j in range(i+1,end+1):
                res=min(res,1+dp[j])
            dp[i]=res

        return dp[0]

