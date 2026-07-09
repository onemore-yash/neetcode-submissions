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
    int fun(TreeNode* node,int& maxi){
        if(!node)return 0;
        int l=max(fun(node->left,maxi),0);
        int r=max(fun(node->right,maxi),0);
        maxi=max(maxi,l+r+node->val);
        return max(l,r)+node->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=root->val;
         fun(root,maxi);
         return maxi;
    }
};
