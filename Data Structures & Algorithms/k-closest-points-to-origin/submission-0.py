class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        store=[]
        for x,y in points:
            store.append((x*x+y*y,x,y))

        store.sort()
        ans=[]
        for i in range(k):
            dist,x,y=store[i]
            ans.append((x,y))

        return ans