/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
        
        /*if(nullptr == head){
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        bool isStarted = false;
        
        while(true){
            if(true == isStarted){
                if(slow  == fast){
                    return true;
                }
            }
            isStarted = true;
            if(nullptr == slow->next){
                return false;
            }else{
                slow =  slow->next;
            }if(nullptr == fast->next || nullptr == fast->next->next){
                return false;
            }else{
                fast = fast->next->next;
            }
        }*/
    }
};