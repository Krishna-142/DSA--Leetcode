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
        int n=0;
        if (head==nullptr || k==0) return head;
        if (head->next==nullptr) return head;
        ListNode* temp=head;
        ListNode* last=new ListNode();
        
        last->next=temp;

        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
            last=last->next;
        }
        last->next=head;
        k=k%n;
        temp=head;
        for(int i=1;i<n-k;i++)
        {
            temp=temp->next;
        }
        ListNode* ans=temp->next;
        temp->next=NULL;
        return ans;

    }
};