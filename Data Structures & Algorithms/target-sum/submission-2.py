class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n=len(nums)
        dp = {}

        def fun(i,cur):
            if(i==n and cur==0):
                return 1

            if(i==n):
                return 0

            if(i,cur) in dp:
                return dp[(i,cur)]

            pos=fun(i+1,cur-nums[i])
            neg=fun(i+1,cur+nums[i])

            dp[(i,cur)]= pos+neg
            return dp[(i,cur)]


        return fun(0,target)