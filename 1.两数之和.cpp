#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

using namespace std;
// @lc code=start
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i = 0, j = 0;
        vector<int> ret;
        multimap<int,int> my_map;
        for(int i = 0; i < nums.size(); i++)
        {
            my_map.insert(pair<int,int>(nums.at(i),i));
        }

        for(map<int,int>::iterator it = my_map.begin(); it != my_map.end(); it++)
        {
            cout << "i = " << it->first << endl;
            
            int temp = target - it->first;
            multimap<int, int>::size_type count = my_map.count(temp);
            
            if(count < 1)
            {
                continue;
            }
            else if(count == 1)
            {
                i = it->second;
                j = my_map.find(temp)->second;
                break;
            }

            multimap<int, int>::iterator iter = my_map.find(temp);

            for(;count > 0; count--,iter++)
            {
                if(count == 2)
                {
                    i = it->second;
                    j = iter->second;
                }
            }
        }
        ret.push_back(i);
        ret.push_back(j);
        sort(ret.begin(),ret.end());
        
        return ret;
    }
};
// @lc code=end

