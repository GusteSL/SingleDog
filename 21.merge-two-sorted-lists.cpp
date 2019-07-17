/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* HeadPtr = NULL;
        ListNode* OperatorPtr;
        ListNode* O1Ptr = l1;
        ListNode* O2Ptr = l2;
        ListNode* NewPtr = NULL;
        while(O1Ptr != NULL || O2Ptr != NULL) {
            if(O1Ptr == NULL && O2Ptr != NULL) {
                NewPtr = O2Ptr;
                O2Ptr = O2Ptr->next;
            } else if(O1Ptr != NULL && O2Ptr == NULL) {
                NewPtr = O1Ptr;
                O1Ptr = O1Ptr->next;
            } else {
                if(O1Ptr->val < O2Ptr->val) {
                    NewPtr = O1Ptr;
                    O1Ptr = O1Ptr->next;
                } else {
                    NewPtr = O2Ptr;
                    O2Ptr = O2Ptr->next;
               }
            }
            if(HeadPtr == NULL) {
                HeadPtr = NewPtr;
                OperatorPtr = HeadPtr;
            } else {
                OperatorPtr->next = NewPtr;
                OperatorPtr = OperatorPtr->next;
            }
        }
        return HeadPtr;
    }
};

