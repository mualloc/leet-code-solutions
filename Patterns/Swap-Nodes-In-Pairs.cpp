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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* next = head->next;
        ListNode* next_next = next->next;
        next->next = head;
        head->next = swapPairs(next_next);

        return next;
    }
};


class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;

        ListNode dummy_head{0, head};
        ListNode* prev = &dummy_head;

        while(head && head->next){
            ListNode* next = head->next;
            ListNode* next_next = next->next;
            next->next = head;
            prev->next = next;
            prev = head;
            head = next_next;
        }
        prev->next = head;
        return dummy_head.next;
    }
};
