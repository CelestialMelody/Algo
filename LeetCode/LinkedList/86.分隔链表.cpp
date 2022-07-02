/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyLow = new ListNode();
        ListNode* dummyHigh = new ListNode();

        ListNode* pLow = dummyLow;
        ListNode* pHigh = dummyHigh;

        while (head != nullptr) {
            if (head->val < x) {
                pLow->next = head;
                pLow = pLow->next;
            } else {
                pHigh->next = head;
                pHigh = pHigh->next;
            }
            head = head->next;
        }

        // while (head != nullptr) {
        //     ListNode* p = head->next; // 隔断
        //     head->next = nullptr;     // 隔断
        //     if (head->val < x) {
        //         pLow->next = head;
        //         pLow = pLow->next;
        //     } else {
        //         pHigh->next = head;
        //         pHigh = pHigh->next;
        //     }
        //     head = p; // 隔断
        // }

        // 需要割断联系 非常关键 简化
        pHigh->next = nullptr;

        //  res前先连接 关键 [1] 0 这种情况
        pLow->next = dummyHigh->next;
        ListNode* res = dummyLow->next;

        dummyHigh->next = nullptr;
        dummyLow->next = nullptr;
        delete dummyHigh;
        delete dummyLow;

        return res;
    }
};
// @lc code=end