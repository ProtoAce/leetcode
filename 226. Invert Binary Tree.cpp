/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 #include <queue>
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        std::queue<TreeNode*> q;

        q.push(root);

        while (!q.empty())
        {
            Treenode* node = q.front();
            q.pop()

            Treenode * tmp = node->left;
            node->left = node->right;
            node->right = tmp;

            if(node->right)
            {
                q.push(node->right);
            }
            if(node->left)
            {
                q.push(node->left);
            }
        }
        return root;
    }
};