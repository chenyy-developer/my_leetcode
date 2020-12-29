/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    
    int climbStairs(int n)
    {
        static int count = 0;
        int ret;

        if (n > 2)
        {
            climbStairs(--n);
            climbStairs(--n);
        }
        else if(n == 2)
        {
            count += 2;
        }
        else if (n == 1)
        {
            count++;
        }
        else if (n == 0)
        {
            ret = count;
            count = 0;
        }

        return ret;
    }
};
// @lc code=end
