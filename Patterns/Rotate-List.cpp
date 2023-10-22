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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        auto list_length{Length(head)};
        k = k % list_length;
        if(!k) return head;
        auto split_point{head}; 
        for(int i = 0; i < list_length - k - 1; ++i) split_point = split_point->next;
        auto new_head{split_point->next};
        split_point->next = nullptr;
        tail->next = head;
        return new_head;
    }
private:
    int Length(ListNode* head){
        auto len{0};
        for(; head; ++len, head = head->next) {tail = head;}
        return len;
    }
    ListNode* tail{};
};
