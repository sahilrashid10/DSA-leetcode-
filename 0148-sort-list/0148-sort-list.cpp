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
    ListNode* findMiddle(ListNode *head){
        ListNode *slow, *fast;
        slow = fast = head;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode *h1, ListNode *h2){
        ListNode dummy(-1);
        ListNode *temp = &dummy;
        while(h1 && h2){
            if(h1->val <= h2->val){
                temp->next = h1;
                h1 = h1->next;
            }else{
                temp->next = h2;
                h2 = h2->next;               
            }
            temp = temp->next;
            temp->next = nullptr;
        }

        if(h1) temp->next = h1;
        if(h2) temp->next = h2;

        return dummy.next;
    }

    ListNode* mergeSort(ListNode *head){
        if(!head || !head->next) return head;

        ListNode *middle = findMiddle(head);
        ListNode *rightStart = middle->next;
        middle->next = nullptr;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(rightStart);

        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         multiset<pair<int, ListNode*>> m;
//         ListNode *temp = head;
//         while(temp){
//             m.insert({temp->val, temp});
//             temp = temp->next;
//         }
//         temp = nullptr;
//         for(auto &[val, node] : m){
//             if(!temp){
//                 temp = node;
//                 head = node;
//             }else{
//                 temp->next = node;
//                 temp = node;
//             }
//         }
//         if(temp)
//         temp->next = nullptr;
//         return head;
//     }
// };