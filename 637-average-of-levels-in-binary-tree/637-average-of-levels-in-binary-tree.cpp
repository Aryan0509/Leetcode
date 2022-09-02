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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        if(root==NULL)
            return ans;
        long long sum=0;
        int count=0;
        queue<TreeNode*> q;
        q.push(root); 
        TreeNode*ptr=NULL;
        q.push(ptr);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==ptr)
            {
                double d=double(sum)/double(count);
                ans.push_back(d);
                sum=0;
                count=0;
                if(q.size()==0)
                {
                    break;
                }
                else q.push(ptr);
            }
            else{
                sum+=temp->val;
                count++;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                    q.push(temp->right);
            }
            
        }
        return ans;
    }
};