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
        
        ListNode *top = l1, *bot = l2;
        ListNode *head = new ListNode(-1), *nex;
        nex = head;
        int rem = 0;
        while(top || bot || rem != 0){
            int sum = 0;
            if(top){
                sum += top->val;
                top = top->next;
            }
            if(bot){
                sum += bot->val;
                bot = bot->next;
            }

            sum += rem;
            rem = sum / 10; 
            sum %= 10;
            ListNode *temp = new ListNode(sum);
            nex->next = temp;
            nex = temp;
        }
        nex = head;
        head = head->next;
        delete nex;
        return head;
    }
};