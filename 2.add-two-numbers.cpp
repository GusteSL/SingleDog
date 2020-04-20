/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if( l1 == NULL ) {
            return l2;
        }
        if( l2 == NULL ) {
            return l1;
        }
        ListNode *p1, *p2, *pr,*result = NULL;
        p1 = l1;
        p2 = l2;
        int val1, val2, tmp_val = 0;
        while( tmp_val != 0 || p1 != NULL || p2 != NULL ) {
            if(result == NULL) {
                pr = new ListNode();
                pr->next = NULL;
                result = pr;
            } else {
                pr->next = new ListNode();
                pr = pr->next;
                pr->next = NULL;
            }
            if(p1 != NULL) {
                val1 = p1->val;
                p1 = p1->next;
            } else {
                val1 = 0;
            }
            if(p2 != NULL) {
                val2 = p2->val;
                p2 = p2->next;
            } else {
                val2 = 0;
            }
            pr->val = (val1 + val2 + tmp_val)%10;
            tmp_val = (val1 + val2 + tmp_val)/10;
        }
        return result;
    }
};
// @lc code=end

