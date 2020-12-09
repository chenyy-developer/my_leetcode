/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits.at(i) + 1 < 10)
            {
                digits.at(i)++;

                return digits;
            }
            else
            {
                digits.at(i) = 0;

                if (i == 0)
                {
                    digits.insert(digits.begin(), 1);

                    return digits;
                }

                continue;
            }
        }

        return digits;
    }
};
// @lc code=end
