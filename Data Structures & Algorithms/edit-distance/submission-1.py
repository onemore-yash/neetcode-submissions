class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m,n=len(word1),len(word2)
        dp=[[-1]*(n+1) for _ in range(m+1)]
        def dfs(i,j):
            if i==m:
                return n-j
            if j==n:
                return m-i

            if word1[i]==word2[j]:
                return dfs(i+1,j+1)
            if dp[i][j]!=-1:
                return dp[i][j]
            res=min(dfs(i+1,j),dfs(i,j+1))
            res=min(dfs(i+1,j+1),res)
            dp[i][j]= res+1
            return dp[i][j]

        return dfs(0,0)