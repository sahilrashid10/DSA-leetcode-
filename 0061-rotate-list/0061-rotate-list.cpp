class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        if(k == 0) return head;

        int size = 0;
        ListNode* temp = head;
        ListNode* tail = NULL;
        while(temp){
            if(temp->next == NULL) tail = temp; // last node
            temp = temp->next;
            size++;
        }
        k = k % size; // imp

        // place temp at size-k th posn-
        temp = head;
        for(int i=1; i<size-k; i++){
            temp = temp->next;
        }
        
        tail->next = head;
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};