/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *this_p, *next_p;
        this_p = head;
        while(this_p != NULL) {
            next_p = this_p->next;
            if(next_p != NULL && this_p->val == next_p->val) {
                this_p->next = next_p->next;
                delete next_p;
            } else {
                this_p = next_p;
            }
        }
        return head;
    }
};
// @lc code=end

