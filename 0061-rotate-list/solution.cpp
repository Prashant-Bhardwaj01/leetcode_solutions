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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int size=1;
        ListNode* helper = head;
        while(helper->next){
             
             helper = helper->next;
             size++;
        }
        helper->next = head;
        k %= size;
        int steps = size - k;
        ListNode* newnode = head;
        for(int i=1;i<steps;i++){
            newnode = newnode->next;
        }
        ListNode* ans = newnode->next;
        newnode->next = nullptr;
        return ans;
    }

};
