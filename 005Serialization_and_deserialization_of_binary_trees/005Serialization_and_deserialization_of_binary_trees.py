# Definition for a binary tree node.
import pdb
from queue import Queue

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        add=""
        if root == None:
            return "N,"
        add += (str(root.val))
        add += ','
        add += self.serialize(root.left)
        add += self.serialize(root.right)
        return add
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        result_data = data.split(',')
        q = Queue()
        for i in result_data:
            q.put(i)
        result = self.from_queue(q)

        return result

    def from_queue(self,result_queue):
        root = result_queue.get()
        if root == 'N':
            return None
        result = TreeNode(int(root))
        result.left = self.from_queue(result_queue)
        result.right = self.from_queue(result_queue)
        return result
        
root = TreeNode(1)
child_1 = TreeNode(2)
child_2 = TreeNode(3)
root.left = child_1
root.right = child_2
child_3 = TreeNode(4)
child_4 = TreeNode(5)
child_2.left = child_3
child_2.right = child_4

# Your Codec object will be instantiated and called as such:
codec = Codec()
#pdb.set_trace()
result = codec.serialize(root)
print(result)
head = codec.deserialize(result)
#pdb.set_trace()
print(codec.serialize(head))