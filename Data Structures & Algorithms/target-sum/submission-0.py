class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n=len(nums)

        def fun(i,cur):
            if(i==n and cur==0):
                return 1

            if(i==n):
                return 0

            pos=fun(i+1,cur-nums[i])
            neg=fun(i+1,cur+nums[i])

            return pos+neg


        return fun(0,target)