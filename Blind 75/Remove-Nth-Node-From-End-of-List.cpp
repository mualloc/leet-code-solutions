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
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode dummy(-1, head);
        ListNode *curr = &dummy, *runner = head;
        while(n--) runner = runner->next;
        while(runner) {
            curr = curr->next;
            runner = runner->next;
        }
        curr->next = curr->next->next;
        
        return dummy.next;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        ListNode *curr = head, *tail = head;
        while(n--) tail = tail->next;
        if(nullptr == tail) return head->next;
        
        while(tail->next) {tail = tail->next; curr = curr->next;}
        curr->next = curr->next->next;
            
        return head;
    }
};