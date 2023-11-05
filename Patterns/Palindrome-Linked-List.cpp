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
    // TC: O(N)
    // SC: O(1)
    bool isPalindrome(ListNode* head) {
        if(nullptr == head->next) return true;
        ListNode *head2{reverseList(splitList(head))};
        while(head && head2) {
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
private:
    ListNode* splitList(ListNode *head) {
        auto slow{head}, fast{head->next};
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto result{slow->next};
        slow->next = nullptr;
        return result;
    }
    ListNode* reverseList(ListNode *head) {
        ListNode* prev{nullptr};
        while(head) {
            auto next{head->next};
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};


// https://leetcode.com/problems/palindrome-linked-list/solutions/64490/my-easy-understand-c-solution/comments/66127
class Solution2 {
public:
    // TC: O(N)
    // SC: O(N)
    bool isPalindrome(ListNode* head) {
        return checkPalindrome(head, head);
    }
private:
    bool checkPalindrome(ListNode*& head, ListNode* curr) {
        if(nullptr == curr) return true;
        auto result = checkPalindrome(head, curr->next) && curr->val == head->val;
        head = head->next;
        return result;
    }
};
