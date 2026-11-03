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
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        return inorder(root, c, k);   
    }

    int inorder(TreeNode* root, int& c, int k) {
        if(root==NULL)
            return -1;
        int left=inorder(root->left, c, k);
        if(left!=-1)
            return left;
        c++;
        if(c==k) 
            return root->val;
        return inorder(root->right, c, k);
    }
};