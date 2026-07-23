class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        rows,cols=len(grid),len(grid[0])

        q=deque()
        ans=0
        fresh=0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==2:
                    q.append((r,c))
                elif grid[r][c]==1:
                    fresh+=1
        if fresh==0:
            return 0
        directions = [(1,0), (-1,0), (0,1), (0,-1)]
        while q and fresh>0:
            for _ in range(len(q)):
                x,y=q.popleft()
                for dx,dy in directions:
                    nx,ny=x+dx,y+dy

                    if 0<=nx<rows and 0<=ny<cols and grid[nx][ny]==1:
                        grid[nx][ny]=2
                        fresh-=1
                        q.append((nx,ny))
            ans+=1

        for r in range(rows):
            for c in range(cols):
                if grid[r][c]==1:
                    return -1

        return ans


        