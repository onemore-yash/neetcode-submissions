class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        rows, cols = len(grid), len(grid[0])
        q = deque()

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 0:
                    q.append((r, c))

        directions = [(1,0), (-1,0), (0,1), (0,-1)]

        while q:
            x,y=q.popleft()

            for dx,dy in directions:
                nx,ny=x+dx,y+dy

                if(0<=nx<rows and 0<=ny<cols and grid[nx][ny]==2147483647):
                    grid[nx][ny]=1+grid[x][y]
                    q.append((nx,ny))

