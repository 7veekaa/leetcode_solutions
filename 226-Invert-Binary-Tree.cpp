#include <iostream>

using namespace std;

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr; 

        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        //root ke 2 baachoo ko jo rev code block se rev hue hai apne me bas ek dusre ki position me rakhdo .
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
