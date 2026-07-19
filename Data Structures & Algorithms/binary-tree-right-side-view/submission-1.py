# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []

        mp = {}
        q = deque()
        q.append((0, root))

        while q:
            level, node = q.popleft()

            if level not in mp:
                mp[level] = node.val

            if node.right:
                q.append((level + 1, node.right))
            if node.left:
                q.append((level + 1, node.left))

        ans = []
        for level in sorted(mp.keys()):
            ans.append(mp[level])

        return ans

