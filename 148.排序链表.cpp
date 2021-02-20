/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        return Method2(head);
    }
    ListNode* Method1(ListNode *const head) {
        if(head == NULL) return head;
        // vector<ListNode*> tmp_val;
        // for(ListNode* p = head; p != NULL; p = p->next) {
        //     tmp_val.push_back(p);
        // }
        // sort(tmp_val.begin(), tmp_val.end(), [](ListNode* p1, ListNode* p2){return p1->val<p2->val;});
        // for(int i = 0; i < tmp_val.size()-1; ++i) {
        //     tmp_val[i]->next = tmp_val[i+1];
        // }
        // tmp_val.back()->next = NULL;
        // return tmp_val[0];
        size_t len = 0;
        ListNode* tmp_p = head;
        while(tmp_p != NULL) {
            tmp_p = tmp_p->next;
            ++len;
        }
        ListNode hidden_head(0);
        hidden_head.next = head;
        for(size_t sort_len = 1; sort_len < len; sort_len *= 2) {
            ListNode *cur = hidden_head.next;
            ListNode *tail = &hidden_head;
            while(cur != NULL) {
                ListNode *left = cur;
                ListNode *right = cut(left, sort_len);
                cur = cut(right, sort_len);
                tail->next = merge(left, right);
                while(tail->next != NULL) {
                    tail = tail->next;
                }
            }
        }
        return hidden_head.next;
    }
    ListNode* cut(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode* pre_right = head;
        for(int i = 1; i < n && pre_right != NULL; ++i, pre_right = pre_right->next){
        }
        ListNode* right;
        if(pre_right == NULL) {
            right = NULL;
        } else {
            right = pre_right->next;
            pre_right->next = NULL;
        }
        return right;
    }
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode *p1 = head1, *p2 = head2;
        ListNode hidden_head(0);
        ListNode *p = &hidden_head;
        while(p1 != NULL && p2 != NULL) {
            if(p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if(p1 == NULL) {
            p->next = p2;
        } else {
            p->next = p1;
        }
        return hidden_head.next;
    }
};
// @lc code=end

