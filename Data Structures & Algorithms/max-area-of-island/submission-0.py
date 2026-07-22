class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        vis = [[False] * cols for _ in range(rows)]

        def dfs(x, y):
            vis[x][y] = True
            area = 1

            for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                nx, ny = x + dx, y + dy

                if (0 <= nx < rows and
                    0 <= ny < cols and
                    not vis[nx][ny] and
                    grid[nx][ny] == 1):
                    area += dfs(nx, ny)

            return area

        maxi = 0

        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1 and not vis[i][j]:
                    maxi = max(maxi, dfs(i, j))

        return maxi
