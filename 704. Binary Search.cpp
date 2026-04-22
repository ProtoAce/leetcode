#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size() == 0)
        {
            return -1;
        }

        int left = 0;
        int right = nums.size()-1;
        int current = left + ((right - left)/2);


        while(left <= right)
        {
            if(nums[current] == target)
            {
                return current;
            }

            if(nums[current] > target)
            {
                right = current - 1;
            }
            else
            {
                left = current + 1;
            }
            current = left + ((right - left)/2);
        }

        return -1;
    }
};