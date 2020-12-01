/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
// @lc code=start
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution
{
public:
    int getVec(int x, vector<double> &bit_vec, vector<double> &value_vec)
    {
        double bit = 1, value = 0;
        static int count = 0;

        if (0 == x)
        {
            count = 0;
            return 1;
        }

        value = x % 10;
        for (int i = 0; i < count; i++)
        {
            bit *= 10;
        }
        if(((bit * value) > INT_MAX) || ((bit * value) < INT_MIN))
        {
            return 0;
        }
        cout << bit << endl;

        bit_vec.push_back(bit);
        value_vec.push_back(value);

        count++;

        getVec((x / 10), bit_vec, value_vec);

        return 1;
    }

    int reverse(int x)
    {
        double ret = 0;
        vector<double> bit_vec;
        vector<double> value_vec;

        if(!getVec(x, bit_vec, value_vec))
        {
            return 0;
        }
        
        for (int i = 0, j = value_vec.size() - 1; i < bit_vec.size(); i++, j--)
        {
            ret += bit_vec.at(i) * value_vec.at(j);
        }

        if ((ret > INT_MAX) || (ret < INT_MIN))
        {
            ret = 0;
        }

        return ret;
    }
};
// @lc code=end
