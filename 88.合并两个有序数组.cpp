/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int j = 0;
        if (n == 0)
        {
            return;
        }
        else if (m == 0)
        {
            nums1 = nums2;

            return;
        }

        for (int i = 0; i < n; i++)
        {
            for (; j < m + n - 1; j++)
            {
                //插在数组最后面
                if (nums2.at(i) >= nums1.at(m + i - 1))
                {
                    nums1.at(m + i) = nums2.at(i);
                    break;
                }
                // 插在最前面
                else if (nums2.at(i) < nums1.at(0))
                {
                    for(int k = m + n -1; k > 0; k--)
                    {
                        nums1.at(k) = nums1.at(k - 1);
                    }

                    nums1.at(0) = nums2.at(i);
                    break;
                }
                // 插在中间
                else if(nums2.at(i) >= nums1.at(j) && nums2.at(i) < nums1.at(j + 1))
                {
                    for(int k = m + n -1; k > j + 1; k--)
                    {
                        nums1.at(k) = nums1.at(k - 1);
                    }

                    nums1.at(j + 1) = nums2.at(i);
                    break;
                }
            }
        }
    }
};
// @lc code=end
