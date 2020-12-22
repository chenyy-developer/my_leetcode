/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if(!head)
        {
            return head;
        }

        ListNode *prev = head;
        ListNode *cur = head->next;

        while (cur)
        {
            if (cur->val == prev->val)
            {
                prev->next = cur->next;
                cur = cur->next;

                continue;
            }

            prev = cur;
            cur = cur->next;
        }

        return head;
    }
};
// @lc code=end
