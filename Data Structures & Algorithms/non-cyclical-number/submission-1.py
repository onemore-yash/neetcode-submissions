class Solution:
    def isHappy(self, n: int) -> bool:
        seen =set()        
        while n!=1 and n not in seen:
            seen.add(n)
            temp=0
            while n>0:
                t=n%10
                temp+=(t*t)
                n//=10
            n=temp

        return True if n==1 else False

        