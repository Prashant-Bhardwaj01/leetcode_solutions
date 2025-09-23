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
    ListNode* removeElements(ListNode* head, int val) {
        
        while(head && head->val == val){
            head = head->next;
        }
        ListNode* helper = head;
        while(helper && helper->next){
            if(helper->next->val == val){
                helper->next = helper->next->next;
            }else{
                helper = helper->next;
            }
        }
        return head;
    }
};
