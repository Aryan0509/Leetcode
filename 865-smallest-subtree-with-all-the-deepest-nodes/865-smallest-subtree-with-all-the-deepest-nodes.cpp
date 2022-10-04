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
    int calcheight(TreeNode*root, unordered_map<TreeNode*,int>&height)
    {
        if(root==NULL)
        {
            height[root]=0;
            return 0;
        }
        height[root]=1+max(calcheight(root->left,height),calcheight(root->right,height));
        return height[root];

    }
    TreeNode* findsub(TreeNode*root, unordered_map<TreeNode*,int>&height)
    {
        if(root==NULL)
            return root;
        if(height[root->left]==height[root->right])
            return root;
        if(height[root->left]>height[root->right])
        {
            return findsub(root->left,height);
        }
        if(height[root->left]<height[root->right])
        {
            return findsub(root->right,height);
        }
        return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*,int>height;
        int h=calcheight(root,height);
        return findsub(root,height);
    }
};