/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

class Solution
{
public:
    void initRomaMap(map<string, int> &roma_map)
    {
        roma_map.insert(pair<string, int>("I", 1));
        roma_map.insert(pair<string, int>("V", 5));
        roma_map.insert(pair<string, int>("X", 10));
        roma_map.insert(pair<string, int>("L", 50));
        roma_map.insert(pair<string, int>("C", 100));
        roma_map.insert(pair<string, int>("D", 500));
        roma_map.insert(pair<string, int>("M", 1000));
        roma_map.insert(pair<string, int>("IV", 4));
        roma_map.insert(pair<string, int>("IX", 9));
        roma_map.insert(pair<string, int>("XL", 40));
        roma_map.insert(pair<string, int>("XC", 90));
        roma_map.insert(pair<string, int>("CD", 400));
        roma_map.insert(pair<string, int>("CM", 900));
    }

    int romanToInt(string s)
    {
        map<string, int> roma_map;
        int ret = 0;

        // 初始化罗马数字对应表
        initRomaMap(roma_map);

        for (int i = 0; i < s.size(); i++)
        {
            string pre, next, str;
            
            if (i < (s.size() - 1))
            {
                pre = s[i];
                next = s[i + 1];
                if ((roma_map.find(pre)->second < roma_map.find(next)->second))
                {
                    str = s.substr(i, 2);
                    i++;
                }
                else
                {
                    str = s.substr(i, 1);
                }
            }
            else
            {
                str = s.substr(i, 1);;
            }
            ret += roma_map.find(str)->second;
        }
        return ret;
    };
};
// @lc code=end
