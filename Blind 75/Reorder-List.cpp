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



// NOTE: BUNU ANLA : https://leetcode.com/problems/reorder-list/discuss/824623/C++-Iterative-+-Recursive-Solution

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {         // slow will point to end of first half
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *reversed = reverseLinkedList(slow->next);
        slow->next = nullptr;
        combineLists(head, reversed);
    }
    
private:
    ListNode* reverseLinkedList(ListNode *head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    
    void combineLists(ListNode *first, ListNode *second){
        while(second){
            ListNode *firstNext = first->next;
            ListNode *secondNext = second->next;
            first->next = second;
            second->next = firstNext;
            first = firstNext;
            second = secondNext;
        }
    }
  
    void combineLists2(ListNode *first, ListNode *second){
        ListNode temp;
        ListNode *tail = &temp;
        
        while(first && second){
            tail->next = first;
            tail = tail->next;
            ListNode *temp = first->next;
            tail->next = second;
            tail = tail->next;
            first = temp;
            second = second->next;
        }
        if(first) tail->next = first;
    }
};


class Solution2 {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> stack;
        ListNode *cur = head, *runner = head;
        while(runner) {
            cur = cur->next;
            runner = runner->next;
            if(runner) runner = runner->next;
        }
        while(cur){
            stack.push(cur);
            cur = cur->next;
        }
        
        while(false == stack.empty()){
            ListNode* temp = head->next;
            head->next = stack.top(); stack.pop();
            head->next->next = temp;
            head = temp;
        }
        head->next = nullptr;
    }
};