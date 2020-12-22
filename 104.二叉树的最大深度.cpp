/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    /*
    *广度优先遍历
    *类似于判断对称二叉树，按层次遍历，
    *每一次while遍历一层
    *每一个for循环将当前队列里面的一层全部弹出，下一层全部入队
    */
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> my_queue;
        TreeNode *cur;
        int count = 0, max = 0;

        if(root == NULL)
        {
            return 0;
        }

        my_queue.push(root);

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
};
// @lc code=end
