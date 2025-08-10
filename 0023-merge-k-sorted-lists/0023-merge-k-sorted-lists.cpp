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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        using NODE = pair<int, ListNode*>;
        //min-heap
        priority_queue<NODE, vector<NODE>, greater<NODE>> h;
        int rows = lists.size();

        ListNode *root=nullptr, *temp=nullptr;
        bool flag = true;

        for(int i=0; i<rows; i++){
            ListNode* temp = lists[i];
            if(temp)
            h.push({temp->val, temp});
        }
        while(!h.empty()){
            auto [value, head] = h.top();
            h.pop();

            if(flag){
                root = head;
                temp = head;
                flag = false;
            }else{
                temp->next = head;
                temp = temp->next;
            }

            if(head->next)
                h.push({head->next->val, head->next});  
        }
        return root;

    }
};














