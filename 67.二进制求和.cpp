/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // 判断是否需要进位
    // 需要改成isCarryOver(char a, char b, int flag)，返回值是进位之后的值（若不进位flag == 0，不会影响计算结果）
    bool isCarryOver(char a, char b, int flag)
    {
        if ((a == '1' && b == '1') || ((a == '1' || b == '1') && flag == 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // 获取相加结果
    char add(char a, char b, int flag)
    {
        if ((a == '1' && b == '1' && flag == 1) || (a == '0' && b == '0' && flag == 1) || (a == '0' && b == '1' && flag == 0) || (a == '1' && b == '0' && flag == 0))
        {
            return '1';
        }
        else
        {
            return '0';
        }
    }

    string addBinary(string a, string b)
    {
        // 设置一个进位标识符，0代表不进位，1代表进位
        int flag = 0;
        const int max_length = a.size() > b.size() ? a.size() : b.size();
        string ret = a.size() > b.size() ? a : b;

        for (int i = a.size() - 1, j = b.size() - 1, l = max_length - 1; l >= 0; i--, j--, l--)
        {
            
            char x = i < 0 ? '0' : a[i];
            char y = j < 0 ? '0' : b[j];

            //判断进位之后的结果，若需要进位flag置1，若不进位flag置0
            if (isCarryOver(x, y, flag))
            {
                ret[l] = add(x, y, flag);
                flag = 1;

                //若首位需要进位
                if (l == 0)
                {
                    ret = "1" + ret;
                }
            }
            else
            {
                // 若不进位，需要将进位标识符置为0
                ret[l] = add(x, y, flag);
                flag = 0;
            }
        }

        return ret;
    }
};
// @lc code=end
