class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res=[]
        nums.sort()
        n=len(nums)
        for i in range(1<<n):
            temp=[]
            valid=True
            for j in range(n):
                if i&(1<<j):
                    if j>0 and nums[j]==nums[j-1] and not (i&(1<<(j-1))):
                        valid=False
                        break
                    temp.append(nums[j])
            if valid:
                res.append(temp)

        return res
                
