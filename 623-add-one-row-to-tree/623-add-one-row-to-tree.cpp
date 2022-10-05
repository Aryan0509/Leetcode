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
    
    void addNode(TreeNode* root, int val, int depth,int height)
    {
        if(height==depth-1)
        {
            TreeNode*ls=root->left;
            TreeNode*rs=root->right;
            TreeNode*ptrl=new TreeNode(val);
            TreeNode*ptrr=new TreeNode(val);
            root->left=ptrl;
            ptrl->left=ls;
            root->right=ptrr;
            ptrr->right=rs;
            return;
        }
        if(root->left)
        {
            addNode(root->left,val,depth,height+1);
        }
        if(root->right)
        {
            addNode(root->right,val,depth,height+1);

        }
        return;
        
        
    }
    
    
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1)
        {
            TreeNode*ptr=new TreeNode(val);
            ptr->left=root;
            return ptr;
        }
        addNode(root,val,depth,1);
        return root;
        
        
    }
};