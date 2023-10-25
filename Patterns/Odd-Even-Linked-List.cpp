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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;

        auto odd_list_tail{head};
        auto even_list{head->next};
        auto even_list_tail{head->next};
        while(even_list_tail && even_list_tail->next) {
            odd_list_tail->next = odd_list_tail->next->next;
            even_list_tail->next = even_list_tail->next->next;
            odd_list_tail = odd_list_tail->next;
            even_list_tail = even_list_tail->next;
        }
        odd_list_tail->next = even_list;

        return head;
    }
};


class Solution2 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;

        ListNode sentinelEven(0 , nullptr);
        ListNode* evenList = &sentinelEven;

        ListNode* tail = head;
        while(tail->next) {
            evenList->next = tail->next;
            evenList = evenList->next;
            tail->next = tail->next->next;
            if(tail->next) tail = tail->next;
        }
        evenList->next = nullptr;
        tail->next = sentinelEven.next;
        return head;
    }
};


class Solution3 {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd_sentinel(0, nullptr);
        ListNode even_sentinel(0, nullptr);
        ListNode* odds{&odd_sentinel};
        ListNode* evens{&even_sentinel};

        const auto append_and_slide{ [] (auto& head, auto element) {head->next = element; head = head->next;} };

        for(auto i{1}; head; ++i, head = head->next) {
            if(i & 1) append_and_slide(odds, head);
            else append_and_slide(evens, head);
        }
        odds->next = even_sentinel.next;
        evens->next = nullptr;
        return odd_sentinel.next;
    }
};
