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
    void rundfss(TreeNode* root, double targetsum,int &count)
    {
        if(root==NULL)
            return;
        if(root->val==targetsum)
        {   count++;
        }
        rundfss(root->left,targetsum-root->val,count);
        rundfss(root->right,targetsum-root->val,count);
        
        
    }
    void rundfs(TreeNode* root, double targetsum,int &count)
    {
        
        if(root==NULL)
            return;
        if(root->val==targetsum)
        {    
            count++;
        }
        rundfs(root->left,targetsum,count);
        rundfs(root->right,targetsum,count);
        rundfss(root->left,targetsum-root->val,count);
        rundfss(root->right,targetsum-root->val,count);
        
    }
    
    int pathSum(TreeNode* root, int targetsum) {
        if(root==NULL)
        {
            return 0;
        }
        int count=0;
        rundfs(root,targetsum,count);
        return count;
    }
};