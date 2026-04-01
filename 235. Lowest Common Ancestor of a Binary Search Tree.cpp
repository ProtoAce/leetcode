
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <queue>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
        {
            return root;
        }

        int larger, smaller;

        if(p->val > q->val)
        {
            larger = p->val;
            smaller = q->val;
        }
        else
        {
            larger = q->val;
            smaller = p->val;
        }

        TreeNode *node = root;

        while(node)
        {
            if(node->val > larger)
            {
                    node = node->left;
            }
            else if (node->val < smaller)
            {
                    node = node->right;
            }
            else
            {
                return node;
            }
        }
        return nullptr;
    }
};