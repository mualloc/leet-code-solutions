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
class Solution2 {
public:
    // TC: O(N)
    // SC: O(1)
    ListNode* reverseKGroup2(ListNode* head, int k) {
        ListNode dummy_head;
        ListNode* tail = &dummy_head;
        while(head){
            ListNode* kth_node = kthNode(head, k);
            ListNode* next = kth_node ? kth_node->next : nullptr;
            if(kth_node) ReverseList(head, k);
            tail->next = kth_node ? kth_node : head;
            tail = head;
            head = next;
        }
        return dummy_head.next;
    }
private:
    ListNode* kthNode(ListNode* head, int k){
        while(--k > 0 && head) head = head->next;
        return head;
    }
    void ReverseList(ListNode* head, int k){
        ListNode* prev = nullptr;
        for(int i = 0; i < k; ++i){
            ListNode* next =  head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
    }
};


class Solution {
public:
    // TC: O(N)
    // SC: O(N/k)
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        for(int i = 0; i < k; ++i){
            if(nullptr == tail) return head;
            tail = tail->next;  // Points to next of actual end!
        }
        ListNode* new_head = ReverseList(head, tail);
        head->next = reverseKGroup(tail, k);    // head is new tail
        return new_head;
    }
private:
    // tail is one past of the actual end
    ListNode* ReverseList(ListNode* head, ListNode* tail){
        ListNode* prev = nullptr;
        while(head != tail){
            ListNode* next =  head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;    // New head
    }
};
