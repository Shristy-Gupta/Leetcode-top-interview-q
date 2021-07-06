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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){return head;}
        ListNode* tail=head->next;
        ListNode* smallhead=reverse(head->next);
        head->next=NULL;
        if(smallhead==NULL){
            return head;
        }
        
        tail->next=head;
        return smallhead;
    }
    ListNode* remove_n_node(ListNode* head, int n){
        if(head==NULL){return NULL;}
        if(n==0){return head;}
        if(n==1){
            ListNode* ans=head->next;
            head->next=NULL;
            return ans;
        }
        head->next=remove_n_node(head->next,n-1);
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      //reverse
        ListNode* reversed=reverse(head);
      //remove nth node
        ListNode* nthnoderemoved=remove_n_node(reversed,n);
      // reverse
        reversed=reverse(nthnoderemoved);
      //return head
        return reversed;
    }
};
