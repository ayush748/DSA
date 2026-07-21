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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        // int sum=0;
        int carry=0;
        ListNode* newnode=new ListNode(NULL);
        ListNode* head=newnode;
        while(temp1!=NULL && temp2!=NULL){
            int sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            int val=sum%10;
            ListNode* curr=new ListNode(val);
            head->next=curr;
            head=curr;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int sum=temp1->val+carry;
            carry=sum/10;
            int val=sum%10;
            ListNode* curr=new ListNode(val);
            head->next=curr;
            head=curr;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int sum=temp2->val+carry;
            carry=sum/10;
            int val=sum%10;
            ListNode* curr=new ListNode(val);
            head->next=curr;
            head=curr;
            temp2=temp2->next;
        }
        if(carry){
            ListNode* curr=new ListNode(carry);
            head->next=curr;
        }
        return newnode->next;
    }
};