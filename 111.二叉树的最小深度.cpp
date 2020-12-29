/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
using namespace std;

class Solution
{
public:
    int getShallow(TreeNode *node)
    {
        queue<TreeNode *> my_queue;
        TreeNode *cur;
        int count = 0, min = 0;

        if (node == NULL)
        {
            return 0;
        }

        my_queue.push(node);

        while (my_queue.size() != 0)
        {
            min++;
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
                    if (cur->left == nullptr && cur->right == nullptr)
                    {
                        goto exit;
                    }

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

    exit:
        return min;
    }

    int minDepth(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        return getShallow(root);
    }
};
// @lc code=end
