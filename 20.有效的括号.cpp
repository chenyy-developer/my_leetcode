/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

//一种括号后面每增加一种相同的括号，那么对应的反括号就应该往后面一个
class Solution
{
public:
    void initBracketsMap(map<char, char> &bracket_map)
    {
        bracket_map.insert(pair<char, char>('(', ')'));
        bracket_map.insert(pair<char, char>('[', ']'));
        bracket_map.insert(pair<char, char>('{', '}'));
    }

    //判断当前括号是第几个相同的括号
    int getPosBracketCount(char pos_bracket, int index, string target)
    {
        int count = 0;

        for (int i = 0; i <= index; i++)
        {
            if (target[i] == pos_bracket)
            {
                count++;
            }
        }

        return count;
    }

    // 获取对应反括号的索引
    int getNegBracketIndex(char pos_bracket, char neg_bracket, string target, int index)
    {
        int count = 0, start_count = 0, start_index = 0, target_index = 0;

        //根据当前括号是相同括号中的第几个获取他在括号中的索引
        for (; start_index < target.size(); start_index++)
        {
            if (start_count == index)
            {
                break;
            }

            if (target[start_index] == pos_bracket)
            {
                start_count++;
            }
        }

        //记录当前括号后面有几个相同的括号，遇到第一个反括号停止
        for (; start_index < target.size(); start_index++)
        {

            if (target[start_index] == neg_bracket)
            {
                break;
            }

            if (target[start_index] == pos_bracket)
            {
                count++;
            }
        }

        for (; start_index < target.size(); start_index++)
        {

            if (target[start_index] == neg_bracket)
            {
                count--;
            }

            //当遇到第一个反括号但是还没遇到相应匹配括号之前遇到相同的括号
            if (target[start_index] == pos_bracket)
            {
                count++;
            }

            if (count == -1)
            {
                target_index = start_index;
                break;
            }
        }

        return target_index;
    }

    // 查看括号个数是否匹配
    bool checkCount(string s)
    {
        int ls_count = 0, rs_count = 0, lm_count = 0, rm_count = 0, ll_count = 0, rl_count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                ls_count++;
                break;

            case ')':
                rs_count++;
                break;

            case '[':
                lm_count++;
                break;

            case ']':
                rm_count++;
                break;

            case '{':
                ll_count++;
                break;

            case '}':
                rl_count++;
                break;

            default:
                break;
            }
        }

        if ((ls_count != rs_count) || (lm_count != rm_count) || (ll_count != rl_count))
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool isValid(string s)
    {
        int flag = 0, ls_count = 0, rs_count = 0, lm_count = 0, rm_count = 0, ll_count = 0, rl_count = 0;
        string str = s;
        map<char, char> bracket_map;

        cout << str << endl;

        //单数个括号肯定有一个不匹配
        if ((s.size() % 2) != 0)
        {
            return false;
        }

        if (!checkCount(s))
        {
            return false;
        }

        initBracketsMap(bracket_map);

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ']' || s[i] == ')' || s[i] == '}')
            {
                continue;
            }

            int index = getNegBracketIndex(s[i], bracket_map.find(s[i])->second, s, getPosBracketCount(s[i], i, s));

            if (index == 0)
            {
                return false;
            }

            if (0 != ((index - i - 1) % 2))
            {
                return false;
            }

            if (!checkCount(s.substr(i + 1, index - i - 1)))
            {
                return false;
            }

            str[i] = '0';
            str[index] = '0';
        }

        //cout << str << endl;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != '0')
            {
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
