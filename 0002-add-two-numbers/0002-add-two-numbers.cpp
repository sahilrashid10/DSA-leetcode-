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
        ListNode* sl_head,*curr;
         sl_head = curr = new ListNode(-1);
        ListNode *t1, *t2;
        t1 = l1; t2 = l2;
        int carry = 0;

        while(t1 != NULL || t2 != NULL || carry){
            int sum = carry;

            if(t1) {sum +=t1->val;t1 = t1->next;}
            if(t2) {sum +=t2->val;t2 = t2->next;}

            ListNode* temp = new ListNode(sum%10);
            carry = sum/10;
            curr->next = temp;
            curr = temp;
        }
        curr = sl_head;
        sl_head = sl_head->next;
        delete(curr);
        return sl_head;
        
    }
};