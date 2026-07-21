class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans=[]
        n=len(nums)
        for i in range(1<<n):
            temp=[]
            for j in range(len(nums)):
                if i&(1<<j):
                    temp.append(nums[j])
            ans.append(temp)
        
        return ans

