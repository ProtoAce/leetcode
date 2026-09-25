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

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

 using namespace std;

class Solution {
public:
    TreeNode* bfs(const vector<int>& preorder, const vector<int>& inorder, TreeNode* node)
    {
        if(preorder.size() == 0)
        {
            node = nullptr;
            return node;
        }
        int middle = preorder[0];
        int split = 0;
        while(inorder[split] != middle)
        {
            split++;
        }
        node = new TreeNode(middle);
        node->left = bfs(std::vector<int>(preorder.begin() + 1, preorder.begin()+ 1 + split), std::vector<int>(inorder.begin(), inorder.begin() + split), node->left);
        node->right = bfs(std::vector<int>(preorder.begin() + split + 1, preorder.end()), std::vector<int>(inorder.begin() + split + 1, inorder.end()), node->right);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode * head = nullptr;
        return bfs(preorder, inorder, head);
    }
};