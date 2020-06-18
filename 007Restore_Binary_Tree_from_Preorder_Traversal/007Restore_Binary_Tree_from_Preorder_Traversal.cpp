#include<string>
#include<iostream>
#include<stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<TreeNode*> path;
        int pos = 0;
        while (pos < S.size()) {
            int level = 0; // 深度
            while (S[pos] == '-') {
                ++level;
                ++pos;
            }

            int value = 0; // 深度后的值
            while (pos < S.size() && isdigit(S[pos])) {
                value = value * 10 + (S[pos] - '0');
                ++pos;
            }
            TreeNode* node = new TreeNode(value); // 写成节点

            if (level == path.size()) {
                if (!path.empty())
                    path.top()->left = node;
            }
            else {
                while (level != path.size()) {
                    path.pop();
                }
                path.top()->right = node;
            }
            path.push(node);
        }
        while (path.size() > 1) {
            path.pop();
        }
        return path.top();
    }

    string FromPreorder(TreeNode* root) {
        string add{};
        if (root == NULL)
            return string("N,");
        add += to_string(root->val);
        add += ",";
        add += FromPreorder(root->left);
        add += FromPreorder(root->right);
        return add;
    }
};

int main() {
    string input_1 = "1-2--3--4-5--6--7";
    string input_2 = "1-2--3---4-5--6---7";
    string input_3 = "1-401--349---90--88";
    Solution fun;
    TreeNode* root_1 = fun.recoverFromPreorder(input_1);
    TreeNode* root_2 = fun.recoverFromPreorder(input_2);
    TreeNode* root_3 = fun.recoverFromPreorder(input_3);
    cout << "root_1:" << fun.FromPreorder(root_1) << endl;
    cout << "root_2:" << fun.FromPreorder(root_2) << endl;
    cout << "root_3:" << fun.FromPreorder(root_3) << endl;
    return 0;
}