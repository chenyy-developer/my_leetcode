/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string getSayCount(string &num_str)
    {
        string say_num_str = "";
        int count = 0, index = 0;
        char var = num_str[0];

        if (num_str.size() == 1)
        {
            num_str = "1" + num_str;

            return num_str;
        }
        //利用字符串拼接，"cout" + "num"
        for (; index < num_str.size(); index++)
        {
            if (num_str[index] != var)
            {
                say_num_str = say_num_str + to_string(count) + var;
                var = num_str[index];
                count = 1;
            }
            else
            {
                count++;
            }

            if (index == num_str.size() - 1)
            {
                say_num_str = say_num_str + to_string(count) + var;
            }
        }

        return say_num_str;
    }

    string countAndSay(int n)
    {
        string num_str = to_string(1);
        int index = 0;

        for (int i = 0; i < n - 1; i++)
        {
            num_str = getSayCount(num_str);
        }

        return num_str;
    }
};
// @lc code=end
