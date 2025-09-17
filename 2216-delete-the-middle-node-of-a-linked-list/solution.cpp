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
    int sizeOfLL(ListNode* head){
        int s = 0;
        ListNode* helper = head;
        while(helper){
            s++;
            helper = helper->next;
        }
        return s;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next ) return nullptr;
        int n = sizeOfLL(head);
        int pos = 0;
        ListNode* helper = head;
        while(helper){
            if(pos == (n/2)-1) break;
            helper = helper->next;
            pos++;
        }
        helper->next = helper->next->next;
        return head;
    }
    
};
