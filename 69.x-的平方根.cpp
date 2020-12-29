/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int low = 0, high = x / 2, ret = 0;
        double middle = x / 4;

        if(x == 1 || x == 0)
        {
            return x;
        }

        while (!(middle * middle  < x && (middle + 1) * (middle + 1) > x))
        {
            if (middle * middle > x)
            {
                high = middle - 1;
                middle = (high + low) / 2;
            }
            else if (middle * middle < x)
            {
                low = middle + 1;
                middle = (high + low) / 2;
            }
            else
            {
                break;
            }
        }

        return middle;
    }
};
// @lc code=end
