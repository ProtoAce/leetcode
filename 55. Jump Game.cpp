#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

class Solution {
public:
    bool canJump(std::vector<int>& nums) {

        int reachable = 0;
        int goal = nums.size()-1;

        for(int i = 0; i < reachable; i++ )
        {
            reachable = std::max(reachable, i + nums[i]);
            if(reachable >= goal)
            {
                return true;
            }
        }
        return false;

    }
};