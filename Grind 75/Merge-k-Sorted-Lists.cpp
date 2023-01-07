/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 */

class Solution {
public:
    // TC: O(N*logK), MC: O(logK)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(0 == lists.size()) return nullptr;     
        else return mergeSort(0, lists.size() - 1, lists);
    }

private:
    ListNode* mergeSort(int start, int end, vector<ListNode*>& lists){
        if(start == end) return lists[start];
        
        int mid = start + (end - start) / 2;
        return mergeLists(mergeSort(start, mid, lists), mergeSort(mid + 1, end, lists));
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        ListNode result;
        ListNode *tail = &result;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next =  l1;
                l1 = l1->next;
            }else{
                tail->next =  l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }     
        tail->next = l1 ? l1 : l2;
          
        return result.next;
    }    
};

class Solution2 {
public:
    // TC: O(N*logK)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(0 == lists.size()) return nullptr;
        
        for(int lSize = lists.size(); lSize > 1; lSize = DivideAndRoundUp(lSize, 2)){
            int i = 0;            
            for(; i + 1 < lSize; i += 2) { lists[i >> 1] = mergeLists(lists[i], lists[i + 1]); }
            if(i < lSize){
                lists[i >> 1] = lists[i];
            }
        }    
        return lists[0];
    }
    
private:
    // https://stackoverflow.com/questions/2422712/rounding-integer-division-instead-of-truncating
    int DivideAndRoundUp(int a, int b){
        return  (a + (b - 1)) / b;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        ListNode result;
        ListNode *tail = &result;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                tail->next =  l1;
                l1 = l1->next;
            }else{
                tail->next =  l2;
                l2 = l2->next;
            }
            tail = tail->next;
        } 
        tail->next = l1 ? l1 : l2;
          
        return result.next;
    }
};

class Solution3 {
public:
    // TC: O(N*K)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode result;
        ListNode *curr = &result;
                
        while(true){
            int minIndex = -1;
            
            for(int i = 0; i < lists.size(); i++){
                ListNode *ln = lists[i];
                if(ln && (minIndex < 0 || ln->val < lists[minIndex]->val)){
                    minIndex = i;
                }
            }
            
            if(minIndex < 0) break;
            else{
                curr->next = lists[minIndex];
                curr = curr->next;
                lists[minIndex] = lists[minIndex]->next;
            }
        }
        
        return result.next;
    }
};


class Solution4 {
public:
    // TC: O(N*logN)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode result;
        ListNode *curr = &result;
        priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> pq;
        
        for(ListNode* ln : lists){
            /*if*/while(ln){
                pq.push(ln);
                ln = ln->next;
            }
        }
                
        while (!pq.empty()) {
            curr->next = pq.top();
            curr = curr->next;
            pq.pop();
            //if(curr->next) pq.push(curr->next);
        }
        
        // Note that this has to be checked!! When pushing elements to PQ, order of elements in the list is not preserved.  
        curr->next = nullptr;
        return result.next;
    }
    
private:
    struct ListNodeComparator {
        bool operator() (ListNode *arg1, ListNode *arg2) { return arg1->val > arg2->val; }
    };
};