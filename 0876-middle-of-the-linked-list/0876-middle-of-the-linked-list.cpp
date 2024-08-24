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
    ListNode* middleNode(ListNode* head) {
        // ListNode *p = head;
        // int count = 0;
        // int mid = 0;
        // while(p != NULL){
        //     count++;
        //     p = p->next;
        // }
        // // dry run it and we come to know we add one extra node to our solution
        // mid = count/2;

        // count = 0;
        // p = head;
        // while(count != mid){
        //     count++;
        //     p = p->next;
        // }
        // return p;
//OPTIMAL SOLUTION(O(N/2)-time)  O(1)-space))
    ListNode* slow, *fast;

    fast = head; slow = head;
    while(fast != NULL && fast->next != NULL){
    fast = fast->next->next;
     slow = slow->next;
    }
    return slow;
    }
};
