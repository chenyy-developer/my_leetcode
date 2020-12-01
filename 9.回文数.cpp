/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int half_revernum = 0;
        if(x < 0 || ((x % 10 == 0) && x != 0))
        {
            return false;
        }

        while(x > half_revernum)
        {
            half_revernum = x % 10 + half_revernum * 10;
            x /= 10;
        }

        //cout << x << "-" << half_revernum << endl;

        return (x == half_revernum) || (x == (half_revernum / 10));
    }
};
// @lc code=end

