#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <queue>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        std::unordered_set<int> numbers(nums.begin(), nums.end());

        int maximum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(!numbers.contains(nums[i]))
            {
                continue;
            }
            int result = 1;
            numbers.erase(nums[i]);
            
            
            int currentNum = nums[i] + 1;
            while(numbers.contains(currentNum))
            {
                result++;
                numbers.erase(currentNum);
                currentNum++;
            }
            currentNum = nums[i] -1;
            while(numbers.contains(currentNum))
            {
                result++;
                numbers.erase(currentNum);
                currentNum--;
            }

            maximum = max(maximum, result);

        }

        return maximum;

        
        
    }
};