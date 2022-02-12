/*
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



// Solution #1 (wrong)
// I first thought of this first solution but realized I did not consider that every left subtree nodes should be lesser than every right subtrees.
  
// class Solution {
// public:
    
//     bool isValidBST(TreeNode* root) {
        
//         if(!root) return true;
//         if(root->left && root->left->val >= root->val) return false;
//         if(root->right && root->right->val <= root->val) return false;
        
//         return isValidBST(root->left) && isValidBST(root->right);
//     }
    

// };

// Solution #2 (Success)

class Solution {
public:
    
    bool isValidBST(TreeNode* root) {
        
        if(!root) return true;

        return checkValidBST(root,LONG_MIN,LONG_MAX);
    }
    
    bool checkValidBST(TreeNode* root,long min, long max) {

        if(!root) return true;
        
        if(root->val <= min) return false;
        if(root->val >= max) return false;
        
        return checkValidBST(root->left,min,root->val)
                &&checkValidBST(root->right,root->val,max);
    }
    

};
