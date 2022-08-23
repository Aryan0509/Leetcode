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
    ListNode* clone(ListNode*head)
    {
        if(head==NULL)
            return head;
        ListNode*ptr=new ListNode(head->val);
        ListNode*head2=ptr;
        ListNode*temp1=head->next;
        ListNode*temp2=head2;
        while(temp1!=NULL)
        {
            ListNode*ptr=new ListNode(temp1->val);
            temp2->next=ptr;
            temp2=temp2->next;
            temp1=temp1->next;
        }
        return head2;
        
    }
       
    ListNode* reverse(ListNode*head)
    {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode*temp=head->next;
        ListNode*ptr=reverse(head->next);
        temp->next=head;
        head->next=NULL;
        return ptr;
    }
    void print(ListNode*head)
    {
        ListNode*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode*head2;
        head2=clone(head);
        head2=reverse(head2);
        // print(head2);
        ListNode*temp2=head2;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            if(temp2->val!=temp->val)
                return false;
            temp2=temp2->next;
            temp=temp->next;
        }
        
        return true;
        
    }
};