/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool equals(char before, char after)
    {
        if ((before == ' ' && after == ' ') || (before != ' ' && after != ' '))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int lengthOfLastWord(string s)
    {

        int length = 0;

        if ((0 == s.size()) || (s == " "))
        {
            return 0;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                length++;
            }
            else
            {
                if (i != s.size() - 1)
                {
                    if (s[i + 1] == ' ')
                    {
                        continue;
                    }
                    else
                    {
                        length = 0;
                    }
                }
            }
        }

        return length;
    }
};
// @lc code=end
