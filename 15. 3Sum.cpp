#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int left;
        int right;

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(nums[i] > 0){
                break;
            }
            
            if(i > 0 && nums[i-1] == nums[i])
            {
                continue;
            }
            
            left = i+1;
            right = nums.size() - 1;

            while(left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if( sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    while(left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }
                    left++;
                    
                    while(right > left && nums[right] == nums[right-1])
                    {
                        right--;
                    }
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else 
                {
                    right --;
                }
            }

        }
        return result;

    };
};