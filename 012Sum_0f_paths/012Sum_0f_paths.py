# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root is None:
            return False
        if root.left is None and root.right is None:
            return sum == root.val
        return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(
            root.right, sum - root.val)


root7 = TreeNode(7)
root2 = TreeNode(2)
root1 = TreeNode(1)
root13 = TreeNode(13)
root11 = TreeNode(11)
root4 = TreeNode(4)
root8 = TreeNode(8)
root04 = TreeNode(4)
root = TreeNode(5)
root.left = root04
root.right = root8
root04.left = root11
root8.left = root13
root8.right = root4
root11.left = root7
root11.right = root2
root4.right = root1
func = Solution()
print(func.hasPathSum(root, 22))
