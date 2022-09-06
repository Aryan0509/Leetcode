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
    bool check(TreeNode*root)
    {
        if(root==NULL)
            return false;
        if(root->val==1)
        {
            return true;
        }
        return check(root->left) or check(root->right);
    }
    TreeNode*prune(TreeNode*root)
    {
        if(root==NULL)
            return root;
        if(root->val==1)
        {
            root->left=prune(root->left);
            root->right=prune(root->right);
            return root;
        }
        else{
            if(check(root->left) or check(root->right))
            {
                root->left=prune(root->left);
                root->right=prune(root->right);
                return root;
            }
            else return NULL;
        }
    }
    
    
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)
            return root;
        return prune(root);
        
    }
};