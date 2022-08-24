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
    ListNode*findmid(ListNode*head)
    {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode*temp=head;
        ListNode*temp2=head;
        while(temp2!=NULL and temp2->next!=NULL and temp2->next->next!=NULL)
        {
            temp=temp->next;
            temp2=temp2->next->next;
        }
        return temp;
        
    }
    ListNode* generate(ListNode*head,int count)
    {
        if(head==NULL or head->next==NULL)
            return head;
        if(count%2!=0)
        {
            ListNode*ptr=generate(head->next,count+1);
            head->next=ptr;
            return head;
        }
        else{
            ListNode*ptr=generate(head->next,count+1);
            ListNode*temp=findmid(ptr);
            head->next=temp->next;
            temp->next=head;
            return ptr;
        }
    }
    
    ListNode* oddEvenList(ListNode* head) {
        return generate(head,1);
    }
};