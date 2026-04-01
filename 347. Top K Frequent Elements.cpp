#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> count;

        if(k == 0)
        {
            return {};
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(count.find(nums[i]) != count.end())
            {
                count[nums[i]] +=1;
            }else
            {
                count[nums[i]] = 1;
            }
        }

        std::multimap<int, int> order;
        for(const auto& [key, value] : count)
        {
            order.insert({value, key});
        }

        std::vector<int> sol;
        int cnt = 0;
        
        for(auto it = order.rbegin(); it != order.rend() && cnt != k; it++ , cnt++)
        {
            sol.push_back(it->second);
        }


        return sol;

    }
};