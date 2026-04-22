#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>


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
    bool isBalanced(TreeNode* root) {
        
        bool balanced = true;
        dfs(root, balanced);
        return balanced;
        
    
    }

    int dfs(TreeNode* node, bool &balanced)
    {
        if(node == nullptr)
        {
            return 0;
        }

        int lDepth = dfs(node->left, balanced);
        int rDepth = dfs(node->right, balanced);

        if(abs(lDepth-rDepth) > 1)
        {
            balanced = false;
        }
    }
};