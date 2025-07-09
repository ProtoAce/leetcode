#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

class Solution {
    public:
        int rob(std::vector<int>& nums) {
            std::vector<int> robbed = {};
            std::vector<int> robbed2 = {};

            if (nums.size() == 1)
            {
                return nums[0];
            }

            for(int i = 0; i < nums.size()-1; i++)
            {
                if(i == 0)
                {
                    robbed.push_back(nums[i]);
                }
                else if (i == 1)
                {
                    robbed.push_back(std::max(robbed[0], nums[i]));
                }
                else
                {
                    robbed.push_back(std::max(robbed[i-1], robbed[i-2] + nums[i]));
                }
            }

            for(int i = 0; i < nums.size()-1; i++)
            {
                if(i == 0)
                {
                    robbed2.push_back(nums[i+1]);
                }
                else if (i == 1)
                {
                    robbed2.push_back(std::max(robbed2[0], nums[i+1]));
                }
                else
                {
                    robbed2.push_back(std::max(robbed2[i-1], robbed2[i-2] + nums[i+1]));
                }
            }

            return std::max(robbed.back(), robbed2.back());
        }
    };

// main() is where program execution begins.
int main() {
    return 0;
 }