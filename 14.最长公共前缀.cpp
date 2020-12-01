/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int count = 1, index = 0, cpm_count = 0;
        string shortest_str, ret_str = "";

        if (strs.size() == 0)
        {
            return ret_str;
        }

        for (int i = 0; i < strs.size(); i++)
        {
            if (strs.at(index).size() >= strs.at(i).size())
            {
                index = i;
            }
        }

        shortest_str = strs.at(index);

        for (; count <= strs.at(index).size(); count++)
        {
            string str = strs.at(index).substr(0, count);

            for (int i = 0; i < strs.size(); i++)
            {
                if (strs.at(i).compare(0, count, str))
                {
                    cpm_count = i;
                    goto end;
                }
            }
        }
    end:
        //规避最短字符串整个都是公共前缀的情况或所有字符串都是单个字符的情况
        if (!(count == shortest_str.size()) || (count == shortest_str.size() && cpm_count != strs.size()))
        {
            count--;
        }

        ret_str = shortest_str.substr(0, count);

        return ret_str;
    }
};
// @lc code=end
