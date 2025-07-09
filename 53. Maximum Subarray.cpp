#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int max = nums[0];
        int current = max;
        int start = 0;
        int end = 0;

        for(int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > current + nums[i])
            {
                start = i;
                current = nums[i];
                end =i;
            }else
            {
                current = current + nums[i];
                end++;
            }
        
            if (current > max)
            {
                max = current;
            }
        }
        return max;
    }
};

// main() is where program execution begins.
int main() {
    return 0;
 }