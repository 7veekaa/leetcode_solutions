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

    bool traverse(TreeNode* a, TreeNode* b){
        if(!a&&!b)return true;
        if(!a||!b)return false;
        if(a->val!=b->val) return false;

        return traverse(a->left, b->left) && traverse(a->right, b->right);
           
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      return  traverse(p,q);
        

     


 
}  
};