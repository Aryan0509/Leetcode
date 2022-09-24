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
    void rundfs(TreeNode* root, int targetSum,vector<int>&v,vector<vector<int>>&ans,int currentsum)
    {
        if(currentsum==targetSum and !root->left and !root->right)
        {
            ans.push_back(v);
            return;
        }
        if(root==NULL)
            return;
        
        if(root->left)
        {
            v.push_back(root->left->val);
            rundfs(root->left,targetSum,v,ans,currentsum+root->left->val);
            v.pop_back();
        }
        if(root->right)
        {   v.push_back(root->right->val);
            rundfs(root->right,targetSum,v,ans,currentsum+root->right->val);
            v.pop_back();
        }
        
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(root==NULL)
            return ans;
        vector<int>v;
        v.push_back(root->val);
        rundfs(root,targetSum,v,ans,root->val);
        return ans;
    }
};