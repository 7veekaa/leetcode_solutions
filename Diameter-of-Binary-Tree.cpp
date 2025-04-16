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
   
    int solve(TreeNode* root, int& sol){
        if(!root) return 0;
        int left=solve(root->left,sol);
        int right=solve(root->right,sol);
        sol=max(sol,left+right);
        return max(left,right)+1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int sol=0;
        solve(root,sol);
        return sol;
        
    }
};