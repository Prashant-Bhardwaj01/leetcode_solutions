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
    ListNode* doubleIt(ListNode* head) {
        ListNode* helper = head;
        ListNode* prev = nullptr;

        while(helper){
            ListNode* next = helper->next;
            helper->next = prev;
            prev = helper;
            helper = next;
        }

        head = prev;
        ListNode* curr = head;
        int carry = 0;
        int sum =0;

        while(curr){
            int multi = curr->val*2;
            sum = carry+multi;
            if(sum > 9) 
                curr->val = sum%10;
            else 
                curr->val = sum;

            carry = sum/10;
            sum = 0;
            curr = curr->next;
        }
        curr = head;
        while(curr->next){
            curr = curr->next;
        }

        if(carry){
            ListNode* neww = new ListNode(carry);
            curr->next = neww;
            
        }

        helper = head;
        prev = nullptr;

        while(helper){
            ListNode* next = helper->next;
            helper->next = prev;
            prev = helper;
            helper = next;
        }

        head = prev;

        return head;


    }
};
