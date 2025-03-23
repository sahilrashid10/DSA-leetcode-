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
        ListNode* fast, *slow;
        fast = new ListNode();
        fast->next = head;
        slow = fast;
        
        while(fast->next){
            if(n-- > 0){
                fast = fast->next;
            }else{
                fast = fast->next;
                slow = slow->next;
            }
        }
        if(slow->next == head) return  head->next;
        slow->next = slow->next->next;
        return head;
    }
};
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(!head->next)
//             return nullptr;
//         ListNode* temp = head;
//         int i=0;
//         while(temp){
//             i++;
//             temp = temp->next;
//         }
//         int x = i - n;
//         temp = head;
//         if(x == 0 ){
//             head = head->next;
//             return head;
//         }
//         while(x > 1){
//             temp = temp->next;
//             x--;    
//         }
        
//         temp->next = temp->next->next;
        
//         return head;
//     }
// };