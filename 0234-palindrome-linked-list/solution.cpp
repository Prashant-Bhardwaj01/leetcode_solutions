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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) break;
        }
        ListNode* prev = nullptr;
        while(slow){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode* helper = head;

        while(prev){
            if(helper->val != prev->val) return false;
            prev = prev->next;
            helper = helper->next;
        }
        return true;
    }
};
