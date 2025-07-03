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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* helper = head;
        
        int size = 0;
        while(helper){
            size++;
            helper = helper->next;
        }
        if(n==size) return head->next;
        helper = head;
        int till = size-n;
        for(int i=0;i<till-1;i++) helper=helper->next;
        if(helper->next)
        helper->next = helper->next->next;
        return head;
    }
};
