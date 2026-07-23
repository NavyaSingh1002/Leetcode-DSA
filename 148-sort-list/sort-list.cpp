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
class Solution 
{
public:
    ListNode* sortList(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* mid=findmid(head);
        ListNode* lefthead=head;
        ListNode* righthead=mid->next;
        mid->next=NULL;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return merge(lefthead, righthead);
    }

    ListNode* findmid(ListNode* head)
    {
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<list2->val)
            {
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else
            {
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1!=NULL)
            temp->next=list1;
        else
            temp->next=list2;
        return dummy->next;
    }
};