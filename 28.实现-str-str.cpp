/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int index = 0;

        if (needle == "")
        {
            return 0;
        }
        else if(haystack.size() < needle.size())
        {
            return -1;
        }

        for (; index < haystack.size(); index++)
        {
            for (int j = 0; j < needle.size(); j++)
            {
                if(index + needle.size() > haystack.size())
                {
                    return -1;
                }

                if (haystack[index + j] != needle[j])
                {
                    break;
                }
                
                if (j == needle.size() - 1)
                {
                    goto end;
                }
            }
        }

    end:
        cout << index - 1 << endl;
        if (index - 1 == haystack.size() - 1)
        {
            if ((needle.size() == 1) && (needle[0] == haystack[haystack.size() - 1]))
            {
                return haystack.size() - 1;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return index;
        }
    }
};
// @lc code=end
