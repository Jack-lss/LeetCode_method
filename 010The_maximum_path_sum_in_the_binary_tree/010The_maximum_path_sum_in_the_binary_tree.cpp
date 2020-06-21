#include<iostream>
#include<algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//
class Solution {
private:
	int maxsum = INT_MIN;
public:
	int maxPath(TreeNode* child) {
		if (child == nullptr)
			return 0;
		int child_left = max(maxPath(child->left), 0);
		int child_right = max(maxPath(child->right), 0);

		int child_sum = child->val + child_left + child_right;

		maxsum = max(maxsum, child_sum);

		return child_sum;
	}

	int maxPathSum(TreeNode* root) {
		maxPath(root);
		return maxsum;
	}
};

int main() {
	Solution suss;
	TreeNode* root_1 = new TreeNode(1);
	root_1->left = new TreeNode(2);
	root_1->right = new TreeNode(3);

	TreeNode* root_2 = new TreeNode(-10);
	root_2->left = new TreeNode(9);
	root_2->right = new TreeNode(20);
	root_2->right->left = new TreeNode(15);
	root_2->right->right = new TreeNode(7);

	cout << "maxPathSum(root_1):" << suss.maxPathSum(root_1) << endl;
	cout << "maxPathSum(root_2):" << suss.maxPathSum(root_2) << endl;
	return 0;
}