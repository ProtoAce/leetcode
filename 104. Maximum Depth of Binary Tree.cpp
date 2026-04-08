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
class Solution {
public:
    int maxDepth(TreeNode* root) {

        stack<pair<TreeNode*, int>> s;

        if(root == nullptr)
        {
            return 0;
        }

        s.push({root, 1});

        int maxDepth = 0;

        while(!s.empty())
        {
            pair<TreeNode*, int> current = s.top();
            s.pop();
            if(current.first != nullptr)
            {
                maxDepth = max(maxDepth, current.second);
                s.push({current.first->left, current.second + 1});
                s.push({current.first->right, current.second + 1});
            }


        }
        return maxDepth;
    }
};