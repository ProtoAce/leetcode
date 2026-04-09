#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size() == 0)
        {
            return 0;
        }

        vector<int> mem(nums.size(), 1); 

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i-1; j >=0; j--)
            {
                if(nums[i] > nums[j])
                {
                    mem[i] = max(mem[j] + 1, mem[i]);
                }
            }
        }

        return *max_element(mem.begin(), mem.end());
    }
};