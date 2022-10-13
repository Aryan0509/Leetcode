/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode*temp=node;
        while(temp->next!=NULL)
        {
            temp->val=temp->next->val;
            if(temp->next->next==NULL)
            {
                temp->next=NULL;
                return;
            }
            temp=temp->next;
        }
    }
};