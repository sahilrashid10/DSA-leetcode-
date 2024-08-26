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
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//NAIVE SOLUTION   SPACE=O(N+N)  TIME=O(N)

        // vector<int>v1,v2;
        // ListNode *temp = head;
        //     while(temp!=NULL){
        //         v1.push_back(temp->val);
        //         temp = temp->next;
        //     }
        //     v2 = v1;
        //     reverse(v2.begin() ,v2.end());
        //     if(v1 == v2)
        //     return true;

            // return false;

// OPTIMAL SOLUTION: SPACE O(1)   TIME O(N)
ListNode* reverse_list(ListNode *head){
    ListNode* c,*p,*n;
    p=NULL;
    c=head;
    while(c!=NULL){
        n = c->next;
        c->next = p;
        p=c;
        c=n;
    }
    return p;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
    ListNode *fast, *slow;
    fast = slow = head;

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow  = slow->next;
    }
    ListNode *newHead = reverse_list(slow->next);
    slow = head;
    while(newHead != NULL){

        if(slow->val != newHead->val)
        return false;

        slow=slow->next;
        newHead=newHead->next; 
    }
    return true;
    }
};