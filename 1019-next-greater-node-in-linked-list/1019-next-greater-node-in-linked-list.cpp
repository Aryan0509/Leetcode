/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>arr;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp=temp->next;
        }
       stack<int>q;
        int n=arr.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            int x=arr[i];
            while(!q.empty() and arr[q.top()]<x)
            {
                ans[q.top()]=x;
                q.pop();
            }
            q.push(i);
        }
        while(!q.empty())
        {
            ans[q.top()]=0;
            q.pop();
        }
        return ans;
    }
};
