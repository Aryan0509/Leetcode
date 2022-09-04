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
    static bool cmp(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
        {
            return p1.first<p2.first;
        }
        return p1.second<p2.second;
    }
    
    void rundfs(TreeNode* root,int r,int c,vector<vector<pair<int,int>>>&store)
    {
        if(root==NULL)
        {
            return;
        }
        store[1000+c].push_back({root->val,r});
        if(root->left)
        {
            rundfs(root->left,r+1,c-1,store);
        }
        if(root->right)
        {
           rundfs(root->right,r+1,c+1,store); 
        }
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<pair<int,int>>>store(2000);
        rundfs(root,0,0,store);
        int mid=1000;
        int s=1000;
        int e=1000;
        while(store[s].size()!=0)
        {
            s--;
        }
        while(store[e].size()!=0)
        {
            e++;
        }
        // int l=e-s+1;
        e--;
        s++;
        vector<vector<pair<int,int>>>ans;
        for(int i=s;i<=e;i++)
        {
            ans.push_back(store[i]);
        }
        // for(auto it:ans)
        // {
        //     sort(it.begin(),it.end());
        // }
        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            sort(ans[i].begin(),ans[i].end(),cmp);
        }
        vector<vector<int>>finalans(n);
        for(int i=0;i<n;i++)
        {
            for(auto it:ans[i])
            {
                finalans[i].push_back(it.first);
            }
        }
        
        return finalans;
    }
};