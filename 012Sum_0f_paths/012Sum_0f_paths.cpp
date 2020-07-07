#include <iostream>
using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    // 最好的情况比广度优先，空间复杂度要好
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return sum == root->val;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

int main()
{
    TreeNode *root7 = &TreeNode(7);
    TreeNode *root2 = &TreeNode(2);
    TreeNode *root1 = &TreeNode(1);
    TreeNode *root13 = &TreeNode(13);
    TreeNode *root11 = &TreeNode(11);
    TreeNode *root4 = &TreeNode(4);
    TreeNode *root8 = &TreeNode(8);
    TreeNode *root04 = &TreeNode(4);
    TreeNode *root = &TreeNode(5);
    root->left = root04;
    root->right = root8;
    root04->left = root11;
    root8->left = root13;
    root->right = root4;
    root11->left = root7;
    root11->right = root2;
    root4->right = root1;
    Solution result;
    bool res = result.hasPathSum(root, 22);
    cout << "hasPathSum(root, 22):" << res << endl;
}