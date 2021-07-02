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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry){
        ListNode* node;
        ListNode* root;
        int sum=0, newcarry=0;
        if(l1==NULL &&l2==NULL){
            if(carry==0)return NULL;
            else{
                return new ListNode(carry);
            }}
        if(l1!=NULL && l2==NULL){
            //copy all the nodes of the l1
            sum=l1->val+carry;
            newcarry=sum/10;
            sum%=10;
            node=new ListNode(sum);
            root=node;
            l1=l1->next;
            while(l1!=NULL){
                sum=l1->val+newcarry;
                newcarry=sum/10;
                sum%=10;
                node->next=new ListNode(sum);
                node=node->next;
                l1=l1->next;
                
            }
            if(newcarry!=0){
                node->next=new ListNode(newcarry);
            }
            return root;
        }
        else if(l1==NULL && l2!=NULL){
            sum=l2->val+carry;
            newcarry=sum/10;
            sum%=10;
            node=new ListNode(sum);
            root=node;
            l2=l2->next;
            while(l2!=NULL){
                sum=l2->val+newcarry;
                newcarry=sum/10;
                sum%=10;
                node->next=new ListNode(sum);
                node=node->next;
                l2=l2->next;
                
            }
            
            if(newcarry!=0){
                node->next=new ListNode(newcarry);
            }
            return root;
        }
        else{
            //recursion
            sum=l2->val+l1->val+carry;
            newcarry=sum/10;
            sum%=10;
            node=new ListNode(sum);
            node->next=addTwoNumbers(l1->next,l2->next,newcarry);
            return node;
            
        }
        
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL &&l2==NULL){return NULL;}
        return addTwoNumbers(l1,l2,0);
        if(l1!=NULL && l2==NULL){
            ListNode* node=new ListNode(l1->val);
            return node;
        }
        if(l1==NULL && l2!=NULL){
             ListNode* node=new ListNode(l2->val);
            return node;
        }
        int sum=l1->val+l2->val;
        
        
    }
};
