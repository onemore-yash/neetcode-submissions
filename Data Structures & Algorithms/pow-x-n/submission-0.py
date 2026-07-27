class Solution:
    def myPow(self, x: float, n: int) -> float:
        def rec(x,t):
            if t==0:
                return 1;
            if t==1:
                return x;
            temp=rec(x,t//2)*rec(x,t//2)
            if t%2==0:
                return temp
            else:
                return temp*x
        if n<0:
            return 1/rec(x,-n)
        return rec(x,n)