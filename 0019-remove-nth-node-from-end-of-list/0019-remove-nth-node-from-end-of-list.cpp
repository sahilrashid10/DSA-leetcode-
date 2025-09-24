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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode *p = head;

        while(n > 0){
            p = p->next;
            n--;
        }
        
        while(p){
            p = p->next;
            temp = temp->next;
        }
        if(temp->next == head){
            return head->next;
        }
        temp->next = temp->next->next;
        return head;
            
    }
};
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int length = 0;
//         ListNode *temp = head;
//         while(temp){
//             length++;
//             temp = temp->next;
//         }
//         length = length -n - 1;
//         if(length < 0)
//             return head->next;

//         temp = head;
//         while(length > 0){
//             length--;
//             temp = temp->next;
//         }
//         temp->next = temp->next->next;
//         return head;
//     }
// };