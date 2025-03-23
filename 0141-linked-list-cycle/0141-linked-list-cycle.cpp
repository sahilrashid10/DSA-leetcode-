/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_set<ListNode*> s;
//         ListNode *temp = head;
//         while(temp){
//             if(s.find(temp) == s.end()){
//                 s.insert(temp);
//                 temp = temp->next;
//             }else return true;
//         }
//         return false;
//     }
// };