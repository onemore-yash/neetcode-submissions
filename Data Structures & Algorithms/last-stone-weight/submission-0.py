import heapq
from typing import List

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        max_heap = [-x for x in stones]
        heapq.heapify(max_heap)

        while len(max_heap)>1:
            f=-max_heap[0]
            heapq.heappop(max_heap)
            s=-max_heap[0]
            heapq.heappop(max_heap)
            if f==s:
                continue
            else:
                diff = f - s
                heapq.heappush(max_heap, -diff)
        
        return -max_heap[0] if max_heap else 0
        
        