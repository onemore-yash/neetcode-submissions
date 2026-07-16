class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry=1
        res=[0]*(len(digits))
        for i in range(len(digits)-1,-1,-1):
            res[i]=(carry+digits[i])%10
            carry=(carry+digits[i])//10
        
        if carry==1:
            res.insert(0,1)

        return res
        