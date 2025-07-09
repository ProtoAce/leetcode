#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>


class Solution {
public:

    int helper(int n, std::unordered_map<int, int>& memo)
    {
        if(memo.find(n) != memo.end())
        {
            return memo[n];
        }
        
        int left = n/2;
        int right = n-left;

        memo[n] = (helper(left, memo) * helper(right, memo)) + (helper(left-1, memo) * helper(right-1, memo));

        return memo[n];
    }

    int climbStairs(int n) {

        std::unordered_map<int,int> memo = {{0,0}, {1,1}, {2,2}, {3,3}};
  
        return helper(n, memo);
        
    }
};