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
    
    ListNode* merge(ListNode* l1,ListNode* l2)
    {   
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        if(l1->val<l2->val)
        {
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
        
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode*temp1=head;
        ListNode* temp2=head;
        while(temp1->next!=NULL and temp1->next->next!=NULL)
        {
            temp1=temp1->next->next;
            temp2=temp2->next;
        }
        ListNode* l2=temp2->next;
        ListNode*l1=head;
        temp2->next=NULL;
        l1=sortList(l1);
        l2=sortList(l2);
        return merge(l1,l2);
    }
};