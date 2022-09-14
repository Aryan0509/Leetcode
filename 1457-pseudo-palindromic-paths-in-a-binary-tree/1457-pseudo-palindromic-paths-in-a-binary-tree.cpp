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
    bool ispalindrome(unordered_map<int,int>&m)
    {
        int flag=1;
        for(auto it:m)
        {
            if(it.second%2==1 and flag==0)
                return false;
            if(it.second%2==1)
            {
                flag=0;
            }   
        }
        return true;
    }
    void rundfs(TreeNode*root,unordered_map<int,int>&m,int &count)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL and root->right==NULL)
        {
            m[root->val]++;
            if(ispalindrome(m))
            {
                m[root->val]--;
                count++;
                return;
            }
            else{
                m[root->val]--;
                return;
            }
        }
        m[root->val]++;
        if(root->left)
        {
            rundfs(root->left,m,count);
        }
        if(root->right)
        {
            rundfs(root->right,m,count);
        }
        m[root->val]--;
        return;
    
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>m;
        int count=0;
        rundfs(root,m,count);
        return count;
    }
};