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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newNode=new TreeNode(val);
        if(root==NULL)
            return newNode;
        TreeNode* temp=root;
        while(1) {
            if(temp->val>val) {
                if(temp->left!=NULL)
                    temp=temp->left;
                else {
                    temp->left=newNode;
                    break;
                }
            }
            else {
                if(temp->right!=NULL)
                    temp=temp->right;
                else {
                    temp->right=newNode;
                    break;
                }
            }
        }
        return root;
    }
};