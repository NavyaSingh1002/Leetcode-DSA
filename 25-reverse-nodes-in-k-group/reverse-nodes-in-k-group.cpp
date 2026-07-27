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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp!=NULL)
        {
            ListNode* kNode=findkNode(temp, k);
            if(kNode==NULL)
            {
                prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kNode->next;
            kNode->next=NULL;
            reverseLL(temp);
            //idenfitying if first group
            if(temp==head)
                head=kNode;
            else
                prevNode->next=kNode;
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }

    ListNode* findkNode(ListNode* temp, int k)
    {
        k=k-1;
        while(temp!=NULL && k>0)
        {
            k--;
            temp=temp->next;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* head)
    {
        ListNode* temp=head;
        ListNode* prev=NULL;
        ListNode* front=NULL;
        while(temp!=NULL)
        {
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        head=prev;
        return head;
    }
};