#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;

class Solution {
 public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
            unordered_map<int, int> mem;

            for(int i = 0; i < nums.size(); i++)
            {
                int difference = target - nums[i];
                if(mem.find(difference) != mem.end())
                {
                    return {mem[difference], i};
                }
                mem.insert(nums[i], i);
                
            }
            return {};
    };
};