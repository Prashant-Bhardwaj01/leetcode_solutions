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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return nullptr;
        ListNode* helperA = headA;
        ListNode* helperB = headB;
        while(helperA != helperB){
            if(helperA) helperA = helperA->next;
            else helperA = headB;
            if(helperB) helperB = helperB->next;
            else helperB = headA;
        }
        return helperB;
    }
};
