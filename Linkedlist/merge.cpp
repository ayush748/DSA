// class compare{
//     public:
//     bool operator()( ListNode* a,ListNode* b)
//     {
//         return a->val > b->val;
//     }
// };
// class Solution {
// public:

//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode* ,vector<ListNode*>,compare> pq;
//         for(int i=0;i<lists.size();i++)
//         {
//             ListNode* listhead=lists[i];
//             if(listhead!=NULL)
//             {
//                 pq.push(listhead);
//             }
//         }
//         ListNode* head=NULL;
//         ListNode* tail=NULL;
//         while(!pq.empty())
//         {
//             ListNode* topnode=pq.top();
//             pq.pop();
//             if(head==NULL)
//             {
//                 head=topnode;
//                 tail=topnode;
//             }
//             else
//             {
//                 tail->next=topnode;
//                 tail=topnode;
//             }
//             if(tail->next!=NULL)
//             {
//                 pq.push(tail->next);
//             }
//         }
//         return head;
//     }
// };