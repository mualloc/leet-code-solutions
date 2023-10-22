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
 
// https://leetcode.com/problems/reverse-linked-list-ii/solutions/2311084/java-c-tried-to-explain-every-step/
// VISUAL: https://leetcode.com/problems/reverse-linked-list-ii/solutions/30709/talk-is-cheap-show-me-the-code-and-drawing/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy_head(0, head);
        ListNode *prev = &dummy_head;
        for(int i = 1; i < left; ++i) prev = prev->next;
        ListNode *curr = prev->next;
        for(int i = 0; i < right - left; ++i) {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        return dummy_head.next;
    }
};


class Solution2 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy_head(0, head);
        ListNode *prev = &dummy_head;
        for(int i = 1; i < left; ++i) prev = prev->next;
        ListNode *curr = prev->next;
        ListNode *prev_copy = prev;
        for(int i = left; i <= right; ++i){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        prev_copy->next->next = curr;   // curr is now the first node after the reversed portion
        prev_copy->next = prev;         // prev is now the last node of the reversed potion
        return dummy_head.next;
    }
};


class Solution3 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev_of_old_head = nullptr, *old_head_of_reversed_list = head;
        int index = 0;
        while(++index < left) {
            prev_of_old_head = old_head_of_reversed_list;
            old_head_of_reversed_list = old_head_of_reversed_list->next;
        }
        
        ListNode *prev = old_head_of_reversed_list;
        ListNode* curr = prev->next;
        while(index++ < right){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        old_head_of_reversed_list->next = curr;
        if(prev_of_old_head) prev_of_old_head->next = prev;
        return prev_of_old_head ? head : prev;
    }
};
