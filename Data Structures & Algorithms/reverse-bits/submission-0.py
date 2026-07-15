class Solution:
    def reverseBits(self, n: int) -> int:
        temp=0
        for i in range(32):
            temp=(temp<<1)|(n&1)
            n=n>>1

        return temp
        