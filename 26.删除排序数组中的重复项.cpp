/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // 新数组索引
        int index = 0;

        if(nums.size() == 1)
        {
            return 1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i < nums.size() - 1)
            {
                if (nums.at(i) == nums.at(i + 1))
                {
                    continue;
                }
                else
                {
                    // 遇到不一样的数字，新数组索引+1，将不一样的插入新数组
                    index++;
                    nums.at(index) = nums.at(i + 1);
                    
                }
            }          
            
        }

        return nums.size() == 0 ? 0 : index + 1;
    }
};
// @lc code=end
