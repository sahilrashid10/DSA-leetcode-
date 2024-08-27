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
        ListNode*sec, *first;
        sec = first = head;
        while(n>0)
        {
            first = first->next;
            
            if(first == NULL)
            return head->next;

            n--;
        }
        while(first->next !=NULL)
        {
            first = first->next;
            sec = sec->next;
        }
        sec->next = sec->next->next;
        return head;
    }
};