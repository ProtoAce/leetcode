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

            for(int i = 0; i < nums.size(); i++)
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
            return robbed.back();
        }
    };

// main() is where program execution begins.
int main() {
    return 0;
 }