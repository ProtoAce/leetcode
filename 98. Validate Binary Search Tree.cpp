#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>


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
    bool isValidBST(TreeNode* root) {

        return dfs(root, LONG_MAX, LONG_MIN);

    }

    bool dfs(TreeNode* node, int max, int min)
    {
        if(!node)
        {
            return true;
        }
        if(node->val <= min || node->val => max)
        {
            return false;
        }

        return dfs(node->left, node->val, min) && dfs(node->right, max, node->val);
     }

};