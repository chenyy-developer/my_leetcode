/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    /*比较两个节点是否相等*/
    bool equals(TreeNode *p, TreeNode *q)
    {
        if((q->val == p->val) && 
        ((p->left && q->left) || !p->left && !q->left)
        && ((p->right && q->right) || !p->right && !q->right))
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    /*深度优先遍历树（非递归算法）
    *1. 对于每个节点来说，先遍历当前节点，
    *2. 然后把右节点压栈，
    *3. 再压左节点(这样弹栈的时候会先拿到左节点遍历，符合深度优先遍历要求)。
    *4. 弹栈，拿到栈顶的节点，
    *5. 如果节点不为空，重复步骤 1；如果为空，结束遍历
    */
    void getVec(TreeNode *p, vector<TreeNode *> &vec)
    {
        stack<TreeNode *> sta;
        TreeNode *cur;

        sta.push(p);

        //cur = sta.top();

        while (sta.size() != 0)
        {
            cur = sta.top();

            vec.push_back(cur);

            sta.pop();
            if (cur->right != nullptr)
            {
                sta.push(cur->right);
            }
            if (cur->left != nullptr)
            {
                sta.push(cur->left);
            }
        }

    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> p_vec, q_vec;

        if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
        {
            return false;
        }

        getVec(q, q_vec);
        getVec(p, p_vec);

        if(p_vec.size() != q_vec.size())
        {
            return false;
        }

        for (int i = 0; i < q_vec.size(); i++)
        {
            if(!equals(p_vec.at(i), q_vec.at(i)))
            {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end
