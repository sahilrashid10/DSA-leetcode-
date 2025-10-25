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
    ListNode* mergeTwoLists(ListNode* i, ListNode* j) {
        ListNode *head = new ListNode(0), *temp;
        temp = head;

        if(!i) return j;
        if(!j) return i;

        while(i && j){
            if(i->val <= j->val){
                temp->next = i;
                i = i->next;
            }else{
                temp->next = j;
                j = j->next;
            }
            temp = temp->next;
        }

        if(i) temp->next = i;
        if(j) temp->next = j;
        
        temp = head->next;
        delete head;
        return temp;
    }
};