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
    
    void reversee(queue<TreeNode*>&q)
    {
        vector<int>arr;
        int n=q.size();
        TreeNode*temp;
        while(n--)
        {
            temp=q.front();
            arr.push_back(temp->val);
            q.pop();
            q.push(temp);
            
        }
        int i=0;
        n=q.size();
        reverse(arr.begin(),arr.end());
        while(n--)
        {
            temp=q.front();
            temp->val=arr[i++];
            q.pop();
            q.push(temp);
            
        }
        
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
     
        TreeNode*ptr=new TreeNode();
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        q.push(ptr);
        while(!q.empty())
        {
            TreeNode*temp=q.front();
            q.pop();
            if(temp==ptr)
            {
                count++;
                if(q.empty())
                {
                    return root;
                }
                if(count%2!=0)
                {
                    reversee(q);
                }
                q.push(ptr);
            }
            else{
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            
        }
        return root;

    }
};