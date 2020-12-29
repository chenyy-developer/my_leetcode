/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
#include <cmath>
using namespace std;

class Solution
{
public:
    // 判断每一层是否对称
    bool isSymmetricPerLay(vector<TreeNode *> &vec)
    {
        int start = 0, end = vec.size() - 1, n = 1;

        if (vec.size() == 1)
        {
            return true;
        }
        else if (vec.size() % 2 == 1)
        {
            return false;
        }

        for (int i = 0; i < vec.size(); i++)
        {
            if (end <= start)
            {
                break;
            }

            if ((vec.at(start) == nullptr && vec.at(end) != nullptr) || (vec.at(start) != nullptr && vec.at(end) == nullptr) || ((vec.at(start) != nullptr && vec.at(end) != nullptr) && (vec.at(start)->val != vec.at(end)->val)))
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
    /*广度优先遍历树
    *1. 对于每个节点来说，先遍历当前节点
    *2. 当前节点出队
    *3. 将当前节点的左右节点入队
    *4. 如果节点不为空，重复1步骤，若为空，结束遍历
    *PS：为了解决本题，我们需要还原输入时的测试用例，即当输入节点的左右节点不全为空时，没有的节点需要在遍历队列中填入null 
    */
    bool isSymmetric(TreeNode *root)
    {

        vector<TreeNode *> vec;
        queue<TreeNode *> my_queue;
        TreeNode *cur;
        int count = 0;

        my_queue.push(root);

        //一次遍历一层，判断每层是否对称
        while (my_queue.size() != 0)
        {
            count = my_queue.size();
            cout << count << endl;

            //将每层的节点都移到遍历队列中去
            for (int i = 0; i < count; i++)
            {
                //遍历当前节点
                cur = my_queue.front();

                // 当前节点出队
                my_queue.pop();

                // 将当前节点插入遍历容器
                vec.push_back(cur);

                //如果节点不为空，若子节点为空，则将nullptr入队
                if (cur != NULL)
                {
                    if (cur->left != nullptr)
                    {
                        my_queue.push(cur->left);
                    }
                    else
                    {
                        my_queue.push(nullptr);
                    }

                    if (cur->right != nullptr)
                    {
                        my_queue.push(cur->right);
                    }
                    else
                    {
                        my_queue.push(nullptr);
                    }
                }
            }

            if (!isSymmetricPerLay(vec))
            {
                return false;
            }

            vec.clear();
        }

        return true;
    }
};
// @lc code=end
