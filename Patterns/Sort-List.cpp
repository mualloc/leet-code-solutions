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

// LEARN AND WRITE SC O(1) solution: https://leetcode.com/problems/sort-list/solutions/1800542/Merge-Sort-Bottom-Up-Implementation-with-comment-in-each-line/
// https://leetcode.com/problems/sort-list/solutions/46712/bottom-to-up-not-recurring-with-o-1-space-complextity-and-o-nlgn-time-complextity/comments/46211
class Solution {
public:
    // TC: O(N * logN)
    // SC: O(logN)
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* middle = getMiddle(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
private:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy_head;
        ListNode* tail = &dummy_head;
        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = list1 ? list1 : list2;
        return dummy_head.next;
    }
    ListNode* getMiddle(ListNode* head){
        if(!head) return head;
        ListNode *slow = head, *fast = head->next;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
