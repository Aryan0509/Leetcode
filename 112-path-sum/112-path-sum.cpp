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
    bool rundfs(TreeNode* root, int targetsum,int sum)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL and root->right==NULL)
        {
            if(sum+root->val==targetsum)
                return true;
            return false;
        }
        return rundfs(root->left,targetsum,sum+root->val) or rundfs(root->right,targetsum,sum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return rundfs(root,targetSum,0);
    }
};