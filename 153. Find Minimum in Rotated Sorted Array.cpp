#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
       int res = nums[0];
       int l = 0;
       int r = nums.size()-1;

       while( l <= r)
       {
        if(nums[l] < nums[r])
        {
            res = min(res, nums[l]);
            break;
        }

        int m = (l + r)/2;
        res = min(res, nums[m]);

        if(nums[l] <= nums[m])
        {
            l = m+1;
        }
        else
        {
            r = m-1;
        }


       }

       return res;


    }
};