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
    void reorderList(ListNode* head) {
        ListNode* s = head, *f = head, *p = nullptr;
        // 1.Find middle of LL
        while(f && f->next){
            f = f->next->next;
            s = s->next;
        }
        f = s->next;
        s->next = nullptr;
        s = f;
        // 2. Reverse after middle
        while(s){
            f = s->next;
            s->next = p;
            p = s;
            s = f;
        }
        //3. connect the normal part and reversed part
        s = head;
        while(f != p && p){
            f = s->next;
            s->next = p;
            p = p->next;
            s->next->next = f;
            s = f;
        }
    }
};