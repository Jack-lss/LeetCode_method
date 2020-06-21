# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self._maxsum = 0

    def maxPath(self, child: TreeNode) -> int:
        if child == None:
            return 0
        child_left = max(self.maxPath(child.left), 0)
        child_right = max(self.maxPath(child.right), 0)
        child_sum = child.val + child_left + child_right
        self._maxsum = max(child_sum, self._maxsum)
        return child_sum

    def maxPathSum(self, root: TreeNode) -> int:
        self.maxPath(root)
        return self._maxsum


if __name__ == '__main__':
    pssk = Solution()
    root_1 = TreeNode(1)
    root_1.left = TreeNode(2)
    root_1.right = TreeNode(3)

    root_2 = TreeNode(-10)
    root_2.left = TreeNode(9)
    root_2.right = TreeNode(20)
    root_2.right.left = TreeNode(15)
    root_2.right.right = TreeNode(7)

    print("maxSum(root_1):{}, maxSum(root_2):{}".format(
        pssk.maxPathSum(root_1), pssk.maxPathSum(root_2)))
