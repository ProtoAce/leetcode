#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

class Solution {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            std::unordered_map<int, int> map;

            if (nums.size() == 2)
            {
                return {0, 1};
            }

            for (int i = 0; i < nums.size(); i++)
            {
                
                if(map.find(target - nums[i]) != map.end())
                {
                    return {map.find(target - nums[i])->second, i};
                }

                map.insert({nums[i], i});
            }
        return {};    
        }
    };

// main() is where program execution begins.
int main() {
    return 0;
 }