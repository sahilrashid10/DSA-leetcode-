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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur, *prev = nullptr, *nex;
        
        cur  = nex = head;
        if(!nex || !nex->next) return head;
        nex = nex->next;

        while(cur){
            cur->next = prev;
            prev = cur;
            cur = nex;
            if(nex)
                nex = nex->next;
        }
        head = prev;
        return head;
    }
};