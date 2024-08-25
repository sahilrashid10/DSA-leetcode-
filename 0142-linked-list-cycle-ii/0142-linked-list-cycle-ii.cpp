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
    ListNode *detectCycle(ListNode *head) {
// good solution        
        // ListNode* temp = head;
        // unordered_map<ListNode* ,int>mp;
        // while(temp != NULL){
        //     mp[temp]++;
        //     temp = temp->next;
        //     if(mp.find(temp) != mp.end())
        //     return temp;
        // }
        // return NULL; 
// OPTIMAL SOLUTION
    ListNode* fast, *slow;
    fast = slow = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        // yes collision
        if(slow == fast){
            fast = head;
            while(slow != fast){
                fast = fast->next;
                slow = slow->next;
        }
        return fast;
    }
    }
        return NULL;
    }
};