// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

//         ListNode* temp1=list1;
//         ListNode* temp2=list2;
//         ListNode* prev=new ListNode(0);
//         ListNode* answer=prev;
//         // node* head=prev;

//         while(temp1!=NULL && temp2!=NULL){
//             if(temp1->val <= temp2->val){
//                 ListNode* newnode=new ListNode(temp1->val);
//                 answer->next=newnode;
//                 temp1=temp1->next;
//             }else{
//                 ListNode* newnode=new ListNode(temp2->val);
//                 answer->next=newnode;
//                 temp2=temp2->next;
//             }
//             answer=answer->next;
//         }
//         while(temp1!=NULL){
//             ListNode* newnode=new ListNode(temp1->val);
//             answer->next=newnode;
//             temp1=temp1->next;
//             answer=answer->next;
//         }
//         while(temp2!=NULL){
//             ListNode* newnode=new ListNode(temp2->val);
//             answer->next=newnode;
//             temp2=temp2->next;
//             answer=answer->next;
//         }

//         return prev->next;

        
//     }
// };