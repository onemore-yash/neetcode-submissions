class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        temp=0
        for i in range(len(nums)):
            temp^=nums[i]
            temp^=i
        temp^=(len(nums))
        return temp
        
        