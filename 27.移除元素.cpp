/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {        
        int index = 0;

        if(nums.size() == 1)
        {
            return nums.at(0) == val ? 0 : 1;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            //最后一个数要单独判断，因为如果不一样index需要+1，一样的话index不许要再改变
            if(i == nums.size() - 1)
            {
                nums.at(index) = nums.at(i);
                index = nums.at(nums.size() - 1) == val ? index : index + 1;
                break;
            }

            if(nums.at(i) == val)
            {
                continue;
            }
            else 
            {
                nums.at(index) = nums.at(i);
                index++;
            }
        }

        cout << index << endl;

        return nums.size() == 0 ? 0 : index;
    }
};
// @lc code=end

