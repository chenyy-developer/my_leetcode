/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {

        int index = 0;

        if(nums.at(0) >= target)
        {
            return 0;
        }
    
        if(nums.at(nums.size() - 1) < target)
        {
            return nums.size();
        }

        for (; index < nums.size(); index++)
        {
            if(target <= nums.at(index))
            {
                break;
            }
        }

        return index;
    }
};
// @lc code=end
