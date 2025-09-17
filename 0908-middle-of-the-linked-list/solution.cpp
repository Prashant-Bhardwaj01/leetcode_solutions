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
    ListNode* middleNode(ListNode* head) {
        int n = sizeOfLL(head);
        int mid = n/2 + 1;
        for(int i =1;i<mid;i++) head = head->next;
        return head;
        
    }
};
