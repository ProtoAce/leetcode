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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {


        std::queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            TreeNode * node = q.front();
            q.pop();

            if(dfs(node, subRoot))
            {
                return true;
            }

            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }


        }
        return false;
        
    }


    bool dfs(TreeNode* node, TreeNode* subRoot)
    {
        if(!node && !subRoot)
        {
            return true;
        }else if (node && !subRoot || !node && subRoot)
        {
            return false;
        }

        if(node->val == subRoot->val)
        {
            return dfs(node->left, subRoot->left) && dfs(node->right, subRoot->right);
        }

        return false;
    }
};