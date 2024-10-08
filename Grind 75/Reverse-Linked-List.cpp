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
        if(nullptr == head || nullptr == head->next) return head;
        
        ListNode* newHead = reverseList(head->next);
        
        head->next->next = head;
        head->next = nullptr;
     
        return newHead;
    }
/*public:
    ListNode* reverseList(ListNode* head) {        
        ListNode *prev = nullptr;
        ListNode *curr = head;
        
        while(nullptr != curr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }*/
};