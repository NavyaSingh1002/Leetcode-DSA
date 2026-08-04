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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode *tail=head;
        int l=1;
        while(tail->next!=NULL) {
            l++;
            tail=tail->next;
        }
        k=k%l;
        if(k==0)
            return head;
        ListNode *temp=head;
        for(int i=1; i<l-k; i++) {
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};