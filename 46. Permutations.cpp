
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <cassert>
#include <string>

using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    
        vector<vector<int>> result; 

        if(nums.size() == 1)
        {
            return {nums};
        }

        for(int i = 0; i < nums.size(); i++)
        {
            vector<int> copy = nums;
            copy.erase(copy.begin() + i);
            
            vector<vector<int>> perms = permute(copy);
            
            for(int j = 0; j < perms.size(); j++)
            {
                vector<int> tmp = {nums[i]};
                tmp.insert(tmp.end(), perms[j].begin(), perms[j].end());
                result.push_back(tmp);
            }
            
        }
        return result;
        
    }

};