# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        path, pos = list(), 0
        while pos < len(S):
            level = 0
            while S[pos] == '-':
                pos+=1
                level+=1
            value = 0
            while pos < len(S) and S[pos].isdigit() :
                value = value * 10 + ord(S[pos]) - ord('0')
                pos+=1
            node = TreeNode(value)
            if level == len(path):
                if path:
                    path[-1].left = node
            else:
                path = path[:level]
                path[-1].right = node
            path.append(node)
        return path[0]             

    def FromPreorder(self, input: TreeNode) -> str:
        add=""
        if input == None:
            return "N,"
        add += (str(input.val))
        add += ','
        add += self.FromPreorder(input.left)
        add += self.FromPreorder(input.right)
        return add

input_1 = "1-2--3--4-5--6--7";
input_2 = "1-2--3---4-5--6---7";
input_3 = "1-401--349---90--88";
fun = Solution()
root_1 = fun.recoverFromPreorder(input_1)
root_2 = fun.recoverFromPreorder(input_2)
root_3 = fun.recoverFromPreorder(input_3)
print(fun.FromPreorder(root_1))
print(fun.FromPreorder(root_2))
print(fun.FromPreorder(root_3))