/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
    //101,104,107三道题的思路都是一样的
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> my_vec;
        vector<int> vec;
        stack<vector<int>> my_stack;
        queue<TreeNode *> my_queue;
        TreeNode *cur;
        int count = 0;

        if(root == NULL)
        {
            return my_vec;
        }

        my_queue.push(root);

        //将每一层压入栈中
        while (my_queue.size() != 0)
        {
            count = my_queue.size();

            //将每层的节点都移到遍历队列中去
            for (int i = 0; i < count; i++)
            {
                //遍历当前节点
                cur = my_queue.front();

                // 当前节点出队
                my_queue.pop();

                // 将当前节点插入数组
                vec.push_back(cur->val);

                //将下一层节点入队
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

            my_stack.push(vec);

            vec.clear();
        }

        count = my_stack.size();
        
        // 利用栈先进后出的方法，将数组顺序反过来
        for (int i = 0; i < count; i++)
        {
            vec = my_stack.top();
            my_stack.pop();
            my_vec.push_back(vec);
        }

        return my_vec;
    }
};
// @lc code=end
