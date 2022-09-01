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
    void rundfs(TreeNode* root,int maxtillnow,int &count)
    {
        if(root->val>=maxtillnow)
        {
            count++;
        }
        if(root->val>maxtillnow)
        {   
            maxtillnow=root->val;
        }
        if(root->left)
        {
            rundfs(root->left,maxtillnow,count);
        }
        if(root->right)
        {
            rundfs(root->right,maxtillnow,count);
        }
    }
    
    int goodNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int count=0;
        int maxtillnow=root->val;
        rundfs(root,maxtillnow,count);
        return count;
        
    }
};