#include<string>
#include<iostream>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val = 0;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // 这里使用string储存，是因为需求为转换为字符串!
    // Encodes a tree to a single string.
    // 没用实际意义，还请看deserialize实现string按','分开的代码，这一部分没有单独做成函数
    string serialize(TreeNode* root) {
        string add{};
        if (root == NULL)
            return string("N,");
        add += to_string(root->val);
        add += ",";
        add += serialize(root->left);
        //add += to_string(root->val);
        add += serialize(root->right);
        //add += to_string(root->val);
        return add;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string* result_data = new string[data.size()];
        int begin = 0;
        int l = 0;
        int count = 0;
        if (data.size() == 0)
            return NULL;
        for (int i = 0;i < data.size();i++)
        {
            if (data[i] == ',')
            {
                string s(data, begin, i - begin);
                result_data[l++] = s;
                begin = i + 1;
                count++;
            }
        }
        // 以上，*result_data储存按','区分的各个val的值
        
        queue<string> result_queue;
        for (int i = 0;i < count;i++)
            result_queue.push(result_data[i]);

        TreeNode* result = from_queue(result_queue);
        return result;
    }

    TreeNode* from_queue(queue<string>& result_queue) {
        string root = result_queue.front();
        result_queue.pop();
        if (root == string("N"))
            return NULL;
        TreeNode* result = new TreeNode;
        result->val = stoi(root);
        result->left = from_queue(result_queue);
        result->right = from_queue(result_queue);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode;
    root->val = 1;
    TreeNode* child_1 = new TreeNode;
    child_1->val = 2;
    root->left = child_1;
    TreeNode* child_2 = new TreeNode;
    child_2->val = 3;
    root->right = child_2;
    TreeNode* child_3 = new TreeNode;
    child_3->val = 4;
    child_2->left = child_3;
    TreeNode* child_4 = new TreeNode;
    child_4->val = 5;
    child_2->right = child_4;
    Codec codec;
    string root_code= codec.serialize(root);
    cout << root_code << endl;
    cout << codec.serialize(codec.deserialize(root_code)) << endl;
    return 0;
}
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));