class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj=[[] for i in range(numCourses)]
        indegree=[0]*numCourses
        for nxt,pre in prerequisites:
            indegree[pre]+=1
            adj[nxt].append(pre)

        q =deque()

        for n in range(numCourses):
            if indegree[n]==0:
                q.append(n)

        finish,output=0,[]
        while q:
            node=q.popleft()
            output.append(node)
            finish +=1
            for nei in adj[node]:
                indegree[nei]-=1
                if indegree[nei]==0:
                    q.append(nei)
        if finish != numCourses:
            return []

        return output[::-1]
