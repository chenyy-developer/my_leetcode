
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
#include <queue>
#include <cmath>
using namespace std;

class Solution
{
public:
    int getDeth(TreeNode *node)
    {
        queue<TreeNode *> my_queue;
        TreeNode *cur;
        int count = 0, max = 0;

        if (node == NULL)
        {
            return 0;
        }

        my_queue.push(node);

        while (my_queue.size() != 0)
        {
            max++;
            count = my_queue.size();

            //将每层的节点都移到遍历队列中去
            for (int i = 0; i < count; i++)
            {
                //遍历当前节点
                cur = my_queue.front();

                // 当前节点出队
                my_queue.pop();

                //如果节点不为空，若子节点为空，则将nullptr入队
                if (cur != NULL)
                {
                    if (cur->left != nullptr)
                    {
                        my_queue.push(cur->left);
                    }

                    if (cur->right != nullptr)
                    {
                        my_queue.push(cur->right);
                    }
                }
            }
        }

        return max;
    }

    bool getResult(TreeNode *node)
    {
        return std::abs(getDeth(node->left) - getDeth(node->right)) > 1 ? false : true;
    }

    bool isBalanced(TreeNode *root)
    {
        int l_depth = 0, r_depth = 0;

        if (root == nullptr)
        {
            return true;
        }

        if(!getResult(root))
        {
            return false;
        }
        
        if(!isBalanced(root->left) || !isBalanced(root->right))
        {
            return false;
        }

        return true;
    }
};
// @lc code=end
